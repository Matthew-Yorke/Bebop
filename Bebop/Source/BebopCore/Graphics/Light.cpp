//*********************************************************************************************************************
//
// File: Light.cpp
//
// Description:
//    This is the light class the create a light source using triangle from a point and a radius.
//
//*********************************************************************************************************************

#include "Light.h"
#include "../Math/MathConstants.h"
#include "GraphicsConstants.h"
#include "../Math/Vector2D.h"
#include "../Math/CollisionDetection/CollisionChecker.h"
#include <algorithm>

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Light
   //
   // Description:
   //    Constructor to set member variables to their default values and then calculate the points for the light.
   //
   // Arguments:
   //    aOriginX        - The X-Coordinate of the light origin point.
   //    aOriginY        - The Y-Coordinate of the light origin point.
   //    aRadius         - The radius of the light source.
   //    aLightColor     - The color of the light source.
   //    aLightIntensity - Th intensity of the light itself.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Light::Light(const float aOriginX, const float aOriginY, const float aRadius, const Color aLightColor,
                const int aLightIntensity) :
      mOriginX(aOriginX), mOriginY(aOriginY), mRadius(aRadius), mLightColor(aLightColor),
      mLightIntensity(aLightIntensity)
   {
      CalculateLight();
   }

   //******************************************************************************************************************
   //
   // Method: AddObject
   //
   // Description:
   //    Add an object that can be blocked by light.
   //
   // Arguments:
   //    apObject - The object to be blocked.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::AddObject(Objects::Object* const apObject)
   {
      bool collides = false;
      Objects::CircleObject* thisLight = new Objects::CircleObject(mOriginX, mOriginY, mRadius, Graphics::Color(0,0,0,0), false);

      // Check if the object being added collides within the light radius
      if (apObject->GetObjectType() == Objects::ObjectType::RECTANGLE)
      {
         collides = Math::RectangleCircleCollision(dynamic_cast<Objects::RectangleObject*>(apObject), thisLight);
      }
      else if (apObject->GetObjectType() == Objects::ObjectType::CIRCLE)
      {
         collides = Math::CircleCircleCollision(dynamic_cast<Objects::CircleObject*>(apObject), thisLight);
      }
      delete thisLight;

      if (collides == true)
      {
         mObjects.push_back(apObject);
      }
   }

   //******************************************************************************************************************
   //
   // Method: Update
   //
   // Description:
   //    Update the light calculations.
   //
   // Arguments:
   //    aElapsedTime - The amount of time since the last update.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::Update(const float aElapsedTime)
   {
      CalculateLight();
   }

   //******************************************************************************************************************
   //
   // Method: CalculateLight
   //
   // Description:
   //    Calculate the point for the light within the range of 360 degrees.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::CalculateLight()
   {
      mPoints.clear();
      mAnglesToCheck.clear();
      Objects::CircleObject* ligthCircle = new Objects::CircleObject(mOriginX, mOriginY, mRadius, Color(0,0,0,0), false);

      for (auto iter = mObjects.begin(); iter != mObjects.end(); ++iter)
      {
         if ((*iter)->GetObjectType() == Objects::ObjectType::RECTANGLE)
         {
            Objects::RectangleObject* tempRectangle = dynamic_cast<Objects::RectangleObject*>(*iter);
            int test = mAnglesToCheck.size();
            if (Math::RectangleCircleCollision(tempRectangle, ligthCircle))
            {
               RectangleCollisionPoint(tempRectangle->GetCoordinateX(), tempRectangle->GetCoordinateY(), tempRectangle);
               RectangleCollisionPoint(tempRectangle->GetCoordinateX() + tempRectangle->GetWidth(), tempRectangle->GetCoordinateY(), tempRectangle);
               RectangleCollisionPoint(tempRectangle->GetCoordinateX(), tempRectangle->GetCoordinateY() + tempRectangle->GetHeight(), tempRectangle);
               RectangleCollisionPoint(tempRectangle->GetCoordinateX() + tempRectangle->GetWidth(), tempRectangle->GetCoordinateY() + tempRectangle->GetHeight(), tempRectangle);
            }
         }
         else if ((*iter)->GetObjectType() == Objects::ObjectType::CIRCLE)
         {
            Objects::CircleObject* tempCircle = dynamic_cast<Objects::CircleObject*>(*iter);
            if (Math::CircleCircleCollision(tempCircle, ligthCircle))
            {
               CircleCollisionPoints(tempCircle);
            }
         }
      }
      delete ligthCircle;

      // Add remaining angles to check and the sort them in ascending order.
      for (auto i = Math::DEGREES_ZERO; i < Math::DEGREES_THREE_SIXTY; i += 15.0F)
      {
         mAnglesToCheck.push_back(i);
      }
      std::sort(mAnglesToCheck.begin(), mAnglesToCheck.end(), [](auto &left, auto &right)
      {
         return left < right;
      });

      bool redundantCollision = false;
      // Check all the angles to be checked.
      for (auto i = mAnglesToCheck.begin(); i < mAnglesToCheck.end(); ++i)
      {
         // Check if the ray collides with an object. In the case it does it would be a redundant calculations so this ray is skipped.
         for (auto iter = mObjects.begin(); iter != mObjects.end(); ++iter)
         {
            if ((*iter)->GetObjectType() == Objects::ObjectType::RECTANGLE)
            {
               if (true == Math::LineRectangleCollision(mOriginX, mOriginY,
                                                        mOriginX + mRadius*cos(*i * Math::RADIANS_CONVERSION), mOriginY + mRadius*sin(*i * Math::RADIANS_CONVERSION),
                                                        dynamic_cast<Objects::RectangleObject*>(*iter),
                                                        nullptr, nullptr))
               {
                  redundantCollision = true;
                  break;
               }
            }
            else if ((*iter)->GetObjectType() == Objects::ObjectType::CIRCLE)
            {
               if (true == Math::LineCircleCollision(mOriginX, mOriginY,
                                                     mOriginX + mRadius*cos(*i * Math::RADIANS_CONVERSION), mOriginY + mRadius*sin(*i * Math::RADIANS_CONVERSION),
                                                     dynamic_cast<Objects::CircleObject*>(*iter),
                                                     nullptr, nullptr))
               {
                  redundantCollision = true;
                  break;
               }
            }
         }

         // If there was no redundancy then add the coordinate to the list.
         if (redundantCollision == false)
         {
            float endPointX = mOriginX + mRadius*cos(*i * Math::RADIANS_CONVERSION);
            float endPointY = mOriginY + mRadius*sin(*i * Math::RADIANS_CONVERSION);

            mPoints.push_back(std::make_pair(*i, std::make_pair(endPointX, endPointY)));
         }

         // Reset redundancy check.
         redundantCollision = false;
      }

      // Sort the list based on degrees in increasing order.
      std::sort(mPoints.begin(), mPoints.end(), [](auto &left, auto &right)
      {
         return left.first < right.first;
      });
   }

   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    Draw the light as triangles based on the points calculated.
   //
   // Arguments:
   //    aWith Color - True  = Draw the light's color.
   //                  False = Only draw the cleared area of the light. 
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::Draw(const bool aWithColor) const
   {
      // Iterate through all the points calculated.
      for (auto iterator = mPoints.begin(); iterator != mPoints.end(); ++iterator)
      {
         // Check if the next item in the vector would be the end, in this case connect the points to the first point
         // in the vector.
         auto isNext = iterator + 1;
         if (isNext == mPoints.end())
         {
            auto firstPoint = mPoints.begin();
            DrawTriangle(iterator->second.first, iterator->second.second, firstPoint->second.first, firstPoint->second.second, aWithColor);
         }
         // Otherwise connect the points to the next point in the vector.
         else
         {
            auto nextPoint = iterator + 1;
            DrawTriangle(iterator->second.first, iterator->second.second, nextPoint->second.first, nextPoint->second.second, aWithColor);
         }
      }
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - Start
//*********************************************************************************************************************

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Private Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: DrawTriangle
   //
   // Description:
   //    Draw the light as triangles based on the points calculated with the very first point being the origin and
   //    passed in points the points at the edge of the triangle.
   //
   // Arguments:
   //    aFirstPointX  - X-Coordinate of the first point added to the gradient triangle.
   //    aFirstPointY  - Y-Coordinate of the first point added to the gradient triangle.
   //    aSecondPointX - X-Coordinate of the second point added to the gradient triangle.
   //    aSecondPointY - Y-Coordinate of the second point added to the gradient triangle.
   //    aWith Color   - True  = Draw the light's color.
   //                    False = Only draw the cleared area of the light.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::DrawTriangle(const float aFirstPointX, const float aFirstPointY, const float aSecondPointX,
                            const float aSecondPointY, const bool aWithColor) const
   {
      float firstDistance = Math::PointDistances(mOriginX, mOriginY, aFirstPointX, aFirstPointY);
      float secondDistance = Math::PointDistances(mOriginX, mOriginY, aSecondPointX, aSecondPointY);

      if (true == aWithColor)
      {
         float firstPecentDistance = (1.0F / mRadius) * firstDistance;
         float secondPecentDistance = (1.0F / mRadius) * secondDistance;

         float firstRed = mLightColor.GetRedColor() - (mLightColor.GetRedColor() * firstPecentDistance);
         float firstGreen = mLightColor.GetGreenColor() - (mLightColor.GetGreenColor() * firstPecentDistance);
         float firstBlue = mLightColor.GetBlueColor() - (mLightColor.GetBlueColor() * firstPecentDistance);
         float firstAlpha = mLightColor.GetAlpha() - (mLightColor.GetAlpha() * firstPecentDistance);

         float secondRed = mLightColor.GetRedColor() - (mLightColor.GetRedColor() * secondPecentDistance);
         float secondGreen = mLightColor.GetGreenColor() - (mLightColor.GetGreenColor() * secondPecentDistance);
         float secondBlue = mLightColor.GetBlueColor() - (mLightColor.GetBlueColor() * secondPecentDistance);
         float secondAlpha = mLightColor.GetAlpha() - (mLightColor.GetAlpha() * secondPecentDistance);

         // Add the points of the triangle along with their colors at the point.
         ALLEGRO_VERTEX vertex[] =
         {
            {mOriginX, mOriginY, 0, 0, 0, al_map_rgba(mLightColor.GetRedColor(), mLightColor.GetGreenColor(),
                                                      mLightColor.GetBlueColor(), mLightColor.GetAlpha())},
            {aFirstPointX, aFirstPointY, 0, 0, 0, al_map_rgba(firstRed, firstGreen,
                                                              firstBlue, firstAlpha)},
            {aSecondPointX, aSecondPointY, 0, 0, 0, al_map_rgba(secondRed, secondGreen,
                                                                secondBlue, secondAlpha)},
         };
         
         // Draw the gradient triangle
         al_draw_prim(vertex, NULL, NULL, 0, 3, ALLEGRO_PRIM_TRIANGLE_STRIP);
      }
      else
      {
         float firstPecentDistance = mLightIntensity - (mLightIntensity * ((1.0F / mRadius) * firstDistance));
         float secondPecentDistance = mLightIntensity - (mLightIntensity * ((1.0F / mRadius) * secondDistance));

         // Add the points of the triangle along with their colors at the point.
         ALLEGRO_VERTEX vertex[] =
         {
            {mOriginX, mOriginY, 0, 0, 0, al_map_rgba(NO_COLOR, NO_COLOR, NO_COLOR, mLightIntensity)},
            {aFirstPointX, aFirstPointY, 0, 0, 0, al_map_rgba(0, 0, 0, firstPecentDistance)},
            {aSecondPointX, aSecondPointY, 0, 0, 0, al_map_rgba(0, 0, 0, secondPecentDistance)},
         };
         
         // Draw the gradient triangle
         al_draw_prim(vertex, NULL, NULL, 0, 3, ALLEGRO_PRIM_TRIANGLE_STRIP);
      }
   }

   //******************************************************************************************************************
   //
   // Method: RectangleCollisionPoint
   //
   // Description:
   //    Checks light collision against a point on a rectangle.
   //
   // Arguments:
   //    aCoordinateX   - X-Coordinate of the point on the rectangle being checked..
   //    aCoordinateY   - Y-Coordinate of the point on the rectangle being checked..
   //    aThisRectangle - Pointer to the rectangle being checked..
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::RectangleCollisionPoint(float aCoordinateX, float aCoordinateY, Objects::Object* aThisRectangle)
   {
      // Get distance from the origin of the light to the point on the rectangle.
      float distance = Math::PointDistances(mOriginX, mOriginY, aCoordinateX, aCoordinateY);

      // Point is outside light radius range.
      if (distance > mRadius)
      {
         return;
      }

      // Check if ray to the point is reachable without passing through the rectangle. Return if it would have to pass
      // through the rectangle.
      // Note: Floor the comparison values to get a close approximation.
      float* x = new float;
      float* y = new float;
      Math::LineRectangleCollision(mOriginX, mOriginY, aCoordinateX, aCoordinateY, dynamic_cast<Objects::RectangleObject*>(aThisRectangle), x, y);
      float collisionDistance = Math::PointDistances(mOriginX, mOriginY, *x, *y);
      if (floor(collisionDistance) < floor(distance))
      {
         return;
      }
      delete x;
      delete y;

      // Check to amke sure the ray doesn't pass through another object from the origin to the rectangle point.
      if (CheckObjectCollisions(aCoordinateX, aCoordinateY, aThisRectangle) == false)
      {
         // Get the angle from the light origin to the rectangle point.
         float angleDegrees = atan2f(aCoordinateY - mOriginY, aCoordinateX - mOriginX) * Math::DEGREES_CONVERSION;
         while (angleDegrees < 0.0F)
         {
            angleDegrees += 360.0F;
         }
         while (angleDegrees > 360.0F)
         {
            angleDegrees -= 360.0F;
         }

         // Add the point to the list of points to draw.
         mPoints.push_back(std::make_pair(angleDegrees, std::make_pair(aCoordinateX, aCoordinateY)));
         // Add angles close by to check so triangles drawn for the lgiht source aren't so drasticly far away from the
         // rectangle point.
         mAnglesToCheck.push_back(angleDegrees + 0.1F);
         mAnglesToCheck.push_back(angleDegrees - 0.1F);
      }
   }

   //******************************************************************************************************************
   //
   // Method: CircleCollisionPoints
   //
   // Description:
   //    Gets light blocking points along a circle.
   //
   // Arguments:
   //    aThisCircle - Pointer to the rectangle being checked.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::CircleCollisionPoints(Objects::CircleObject* aThisCircle)
   {  
      // Find the angle fromt he circle center to the circle edge where the light would pass through with a single collision.
      float distance = Math::PointDistances(mOriginX, mOriginY, aThisCircle->GetCoordinateX(), aThisCircle->GetCoordinateY());
      float angleOriginToEdge = asinf(aThisCircle->GetRadius() * sin(90.0F * Math::RADIANS_CONVERSION) / distance) * Math::DEGREES_CONVERSION;
      float angleCircleToEdge = 180.0F - 90.0F - angleOriginToEdge;

      // Get the angle from light origin to the circle center.
      float angleDegrees = atan2f(aThisCircle->GetCoordinateY() - mOriginY, aThisCircle->GetCoordinateX() - mOriginX) * Math::DEGREES_CONVERSION;
      while (angleDegrees < 0.0F)
      {
         angleDegrees += 360.0F;
      }
      while (angleDegrees > 360.0F)
      {
         angleDegrees -= 360.0F;
      }

      // Find the edge points and angle to the point form the light origin for the clockwise angle.
      float cwSide = angleDegrees + (180.0F - angleCircleToEdge);
      float cwX = aThisCircle->GetCoordinateX() + aThisCircle->GetRadius()*cos(cwSide * Math::RADIANS_CONVERSION);
      float cwY = aThisCircle->GetCoordinateY() + aThisCircle->GetRadius()*sin(cwSide * Math::RADIANS_CONVERSION);
      // Find the angle from the origin to 
      float cwAngleFromOrigin = angleDegrees + angleOriginToEdge;
      // Check to make sure the ray doesn't pass through other light blocking object to this edge.
      if (CheckObjectCollisions(cwX, cwY, aThisCircle) == false)
      {
         mPoints.push_back(std::make_pair(cwAngleFromOrigin, std::make_pair(cwX, cwY)));
         mAnglesToCheck.push_back(cwAngleFromOrigin + 0.1F);
      }

      // Find the edge points and angle to the point form the light origin for the counterclockwise angle.
      float ccwSide = angleDegrees - (180.0F - angleCircleToEdge);
      float ccwX = aThisCircle->GetCoordinateX() + aThisCircle->GetRadius()*cos(ccwSide * Math::RADIANS_CONVERSION);
      float ccwY = aThisCircle->GetCoordinateY() + aThisCircle->GetRadius()*sin(ccwSide * Math::RADIANS_CONVERSION);
      float ccwAngleFromOrigin = angleDegrees - angleOriginToEdge;
      // Check to make sure the ray doesn't pass through other light blocking object to this edge.
      if (CheckObjectCollisions(ccwX, ccwY, aThisCircle) == false)
      {
         mPoints.push_back(std::make_pair(ccwAngleFromOrigin, std::make_pair(ccwX, ccwY)));
         mAnglesToCheck.push_back(ccwAngleFromOrigin - 0.1F);
      }

      // Find some collision points along the circle.
      float* x = new float;
      float* y = new float;
      for (float i = ccwAngleFromOrigin + 1.0F; i < cwAngleFromOrigin; i += 1.0F)
      {
         Math::LineCircleCollision(mOriginX, mOriginY,
                                   mOriginX + mRadius*cos(i * Math::RADIANS_CONVERSION), mOriginY + mRadius*sin(i * Math::RADIANS_CONVERSION),
                                   aThisCircle,
                                   x, y);

         if (CheckObjectCollisions(*x, *y, aThisCircle) == false)
         {
            mPoints.push_back(std::make_pair(i, std::make_pair(*x, *y)));
            
         }
      }
      delete x;
      delete y;
   }

   //******************************************************************************************************************
   //
   // Method: CheckObjectCollisions
   //
   // Description:
   //    Checks if the ray from the light origin to the end point will pass through any other objects. Returns a bool
   //    based on the results.
   //
   // Arguments:
   //    aEndPointX - The X-Coordinate of the end point being checked against the light origin.
   //    aEndPointY - The Y-Coordinate of the end point being checked against the light origin.
   //    testingObject - The object being tested, used to not test itself.
   //
   // Return:
   //    True  - The ray passes through some other object.
   //    False - The ray doesn't pass through any other objects.
   //
   //******************************************************************************************************************
   bool Light::CheckObjectCollisions(float aEndPointX, float aEndPointY, Objects::Object* testingObject)
   {
      for (auto iter = mObjects.begin(); iter != mObjects.end(); ++iter)
      {
         // Skip checking itself.
         if (*iter == testingObject)
         {
            continue;
         }
         // Object check is rectangular.
         else if ((*iter)->GetObjectType() == Objects::ObjectType::RECTANGLE)
         {
            
            // Check if there is collision against the ray. Collision would mean the ray passed through this object
            // before reaching the reaching the end point.
            if (true == Math::LineRectangleCollision(mOriginX, mOriginY,
                                                     aEndPointX, aEndPointY,
                                                     dynamic_cast<Objects::RectangleObject*>(*iter),
                                                     nullptr, nullptr))
            {
               return true;
            }
         }
         // Object check is circular.
         else if ((*iter)->GetObjectType() == Objects::ObjectType::CIRCLE)
         {
            // Check if there is collision against the ray. Collision would mean the ray passed through this object
            // before reaching the reaching the end point.
            if (true == Math::LineCircleCollision(mOriginX, mOriginY,
                                                  aEndPointX, aEndPointY,
                                                  dynamic_cast<Objects::CircleObject*>(*iter),
                                                  nullptr, nullptr))
            {
               return true;
            }
         }
      }

      return false;
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}