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
#include <limits>

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
   }

   //******************************************************************************************************************
   //
   // Method: GetCoordinateX
   //
   // Description:
   //    UReturn the origin X-Coordinate of the light source.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the float value that is the X-Coordinate of the light source origin.
   //
   //******************************************************************************************************************
   float Light::GetCoordinateX()
   {
      return mOriginX;
   }

   //******************************************************************************************************************
   //
   // Method: SetCoordinateX
   //
   // Description:
   //    Update the X-Coordinate origin point for the light source.
   //
   // Arguments:
   //    aCoordinateX - The float value to update the X-Cooridnate origin point of the light source.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::SetCoordinateX(float aCoordinateX)
   {
      mOriginX = aCoordinateX;
   }
   
   //******************************************************************************************************************
   //
   // Method: GetCoordinateY
   //
   // Description:
   //    UReturn the origin Y-Coordinate of the light source.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the float value that is the Y-Coordinate of the light source origin.
   //
   //******************************************************************************************************************
   float Light::GetCoordinateY()
   {
      return mOriginY;
   }
   
   //******************************************************************************************************************
   //
   // Method: SetCoordinateY
   //
   // Description:
   //    Update the Y-Coordinate origin point for the light source.
   //
   // Arguments:
   //    aCoordinateY - The float value to update the Y-Cooridnate origin point of the light source.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::SetCoordinateY(float aCoordinateY)
   {
      mOriginY = aCoordinateY;
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
   void Light::Update(const float aElapsedTime, std::vector<Objects::Object*> aBlockingObjects)
   {
      CalculateLight(aBlockingObjects);
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
   void Light::CalculateLight(std::vector<Objects::Object*> aBlockingObjects)
   {
      mPoints.clear();
      mAnglesToCheck.clear();
      mObjects.clear();
      Objects::CircleObject* ligthCircle = new Objects::CircleObject(mOriginX, mOriginY, mRadius, Color(0,0,0,0), false);
      std::vector<Objects::Object*> mObjects;
      std::vector<std::pair<float, float>>* pCollisionPoints = new std::vector<std::pair<float, float>>;

      // Check which objects will collide with the light and store those objects.
      bool objectLigthCollides = false;
      for (auto objectIterator = aBlockingObjects.begin(); objectIterator != aBlockingObjects.end(); ++objectIterator)
      {
         if ((*objectIterator)->GetObjectType() == Objects::ObjectType::RECTANGLE)
         {
            objectLigthCollides = Math::RectangleCircleCollision(dynamic_cast<Objects::RectangleObject*>(*objectIterator), ligthCircle, nullptr);
         }
         else if ((*objectIterator)->GetObjectType() == Objects::ObjectType::CIRCLE)
         {
            objectLigthCollides = Math::CircleCircleCollision(dynamic_cast<Objects::CircleObject*>(*objectIterator), ligthCircle, nullptr);
         }

         if (objectLigthCollides == true)
         {
            mObjects.push_back(*objectIterator);
            objectLigthCollides = false;
         }
      }

      // Gather points of objects to check for light being able to reach.
      for (auto collideObjectIterator = mObjects.begin(); collideObjectIterator != mObjects.end(); ++collideObjectIterator)
      {
         if ((*collideObjectIterator)->GetObjectType() == Objects::ObjectType::RECTANGLE)
         {
            // Convert object to rectangle type since we know the type to be rectangle.
            Objects::RectangleObject* tempCollideRectangle = dynamic_cast<Objects::RectangleObject*>(*collideObjectIterator);

            // Check if this object overlaps with other objects within the light's range and gather those collision points.
            for (auto overlapCheckIterator = collideObjectIterator + 1; overlapCheckIterator != mObjects.end(); ++overlapCheckIterator)
            {
               // The object being checked aginst is a rectangle.
               if ((*overlapCheckIterator)->GetObjectType() == Objects::ObjectType::RECTANGLE)
               {
                  if (true == Math::RectangleRectangleCollision(tempCollideRectangle,
                                                                dynamic_cast<Objects::RectangleObject*>(*overlapCheckIterator),
                                                                nullptr))
                  {
                     RectangleRectangleCollisionPoints(tempCollideRectangle, dynamic_cast<Objects::RectangleObject*>(*overlapCheckIterator), pCollisionPoints);
                  }
               }
               // The object being checked against is a circle.
               else if ((*overlapCheckIterator)->GetObjectType() == Objects::ObjectType::CIRCLE)
               {
                  Math::RectangleCircleCollision(tempCollideRectangle,
                                                 dynamic_cast<Objects::CircleObject*>(*overlapCheckIterator),
                                                 pCollisionPoints);
               }
            }

            // Find collision points of circle and rectangle.
            Math::RectangleCircleCollision(tempCollideRectangle, ligthCircle, pCollisionPoints);

            // Gather collision points for this rectangle.
            // Top Left
            pCollisionPoints->push_back(std::make_pair(tempCollideRectangle->GetCoordinateX(), tempCollideRectangle->GetCoordinateY()));
            // Top Right
            pCollisionPoints->push_back(std::make_pair(tempCollideRectangle->GetCoordinateX() + tempCollideRectangle->GetWidth(), tempCollideRectangle->GetCoordinateY()));
            // Bottom Left
            pCollisionPoints->push_back(std::make_pair(tempCollideRectangle->GetCoordinateX(), tempCollideRectangle->GetCoordinateY() + tempCollideRectangle->GetHeight()));
            // Bottom Right
            pCollisionPoints->push_back(std::make_pair(tempCollideRectangle->GetCoordinateX() + tempCollideRectangle->GetWidth(), tempCollideRectangle->GetCoordinateY() + tempCollideRectangle->GetHeight()));
         }
         else if ((*collideObjectIterator)->GetObjectType() == Objects::ObjectType::CIRCLE)
         {
            // Convert object to rectangle type since we know the type to be rectangle.
            Objects::CircleObject* tempCollideCircle = dynamic_cast<Objects::CircleObject*>(*collideObjectIterator);

            // Check if this object overlaps with other objects within the light's range and gather those collision points.
            for (auto overlapCheckIterator = collideObjectIterator + 1; overlapCheckIterator != mObjects.end(); ++overlapCheckIterator)
            {
               // The object being checked aginst is a rectangle.
               if ((*overlapCheckIterator)->GetObjectType() == Objects::ObjectType::RECTANGLE)
               {
                  Math::RectangleCircleCollision(dynamic_cast<Objects::RectangleObject*>(*overlapCheckIterator),
                                                 tempCollideCircle,
                                                 pCollisionPoints);
               }
               // The object being checked against is a circle.
               else if ((*overlapCheckIterator)->GetObjectType() == Objects::ObjectType::CIRCLE)
               {
                  Math::CircleCircleCollision(dynamic_cast<Objects::CircleObject*>(*collideObjectIterator),
                                              tempCollideCircle,
                                              pCollisionPoints);
               }
            }
            
            // Find collision points of circle and circle.
            //Math::CircleCircleCollision(tempCircle, ligthCircle, pCollisionPoints);
            
            // Gather collision points for this circle.
            CircleCollisionPoints(tempCollideCircle, pCollisionPoints);
         }
      }

      // Resolve the found points to see if they can be reached.
      for (auto pointIter = pCollisionPoints->begin(); pointIter != pCollisionPoints->end(); ++pointIter)
      {
         // Gather the X-Coordinate and Y-Coordinate of the point.
         float x = pointIter->first;
         float y = pointIter->second;

         // Get the angle from light origin to the point.
         float angleDegrees = atan2f(y - mOriginY, x - mOriginX) * Math::DEGREES_CONVERSION;
         while (angleDegrees < 0.0F)
         {
            angleDegrees += 360.0F;
         }
         while (angleDegrees > 360.0F)
         {
            angleDegrees -= 360.0F;
         }

         // Add checks to close surrounding angles
         mAnglesToCheck.push_back(std::make_pair(angleDegrees - 0.1F, true));
         mAnglesToCheck.push_back(std::make_pair(angleDegrees + 0.1F, true));

         // Handle the case if the point is further than the light's radius.
         float circleMaxDistanceX = mOriginX + mRadius * cos(angleDegrees * Math::RADIANS_CONVERSION);
         float circleMaxDistanceY = mOriginY + mRadius * sin(angleDegrees * Math::RADIANS_CONVERSION);
         if (Math::PointDistances(mOriginX, mOriginY, x, y) >
             Math::PointDistances(mOriginX, mOriginY,  circleMaxDistanceX, circleMaxDistanceY))
         {
            continue;
         }

         // Check if the ray from the light to the point collides with any object.
         bool collidesObject = false;
         for (auto iter = mObjects.begin(); iter != mObjects.end(); ++iter)
         {
            // Object being checked for collision is a rectangle.
            if ((*iter)->GetObjectType() == Objects::ObjectType::RECTANGLE)
            {
               if (true == Math::LineRectangleCollision(mOriginX, mOriginY,
                                                        x, y,
                                                        dynamic_cast<Objects::RectangleObject*>(*iter),
                                                        nullptr, nullptr))
               {
                  collidesObject = true;
                  break;
               }
            }
            // Object being checked for collison is a circle.
            else if ((*iter)->GetObjectType() == Objects::ObjectType::CIRCLE)
            {
               if (true == Math::LineCircleCollision(mOriginX, mOriginY,
                                                     x, y,
                                                     dynamic_cast<Objects::CircleObject*>(*iter),
                                                     nullptr, nullptr))
               {
                  collidesObject = true;
                  break;
               }
            }
         }

         // If the ray  does not collide with an object, then add this to the vector of points for drawing.
         if (collidesObject == false)
         {
            mPoints.push_back(std::make_pair(angleDegrees, std::make_pair(pointIter->first, pointIter->second)));
         }
      }

      // Add the angles for the sweeping points.
      for (auto degrees = 0.0F; degrees < 360.0F; degrees += 15.0F)
      {
         mAnglesToCheck.push_back(std::make_pair(degrees, false));
      }

      // Sort the angles to check in ascending order and remove duplicates.
      std::sort(mAnglesToCheck.begin(), mAnglesToCheck.end(), [](auto &left, auto &right)
      {
         return left < right;
      });
      mAnglesToCheck.erase(std::unique(mAnglesToCheck.begin(), mAnglesToCheck.end()), mAnglesToCheck.end());

      // Check all angles to be checked
      float* x = new float;
      float* y = new float;
      float tempX = std::numeric_limits<float>::max();
      float tempY = std::numeric_limits<float>::max();
      for (auto angleIter = mAnglesToCheck.begin(); angleIter != mAnglesToCheck.end(); ++angleIter)
      {
         // Check the angle for the ray against every object the circle is colliding with.
         for (auto objectIter = mObjects.begin(); objectIter != mObjects.end(); ++objectIter)
         {
            // The object being checked is a rectangle object.
            if ((*objectIter)->GetObjectType() == Objects::ObjectType::RECTANGLE)
            {
               // Check if the ray collides with this rectangle object.
               if (true == Math::LineRectangleCollision(mOriginX, mOriginY,
                                                        mOriginX + mRadius * cos(angleIter->first * Math::RADIANS_CONVERSION),
                                                        mOriginY + mRadius * sin(angleIter->first * Math::RADIANS_CONVERSION),
                                                        dynamic_cast<Objects::RectangleObject*>(*objectIter), x, y))
               {
                  if (Math::PointDistances(mOriginX, mOriginY, tempX, tempY) > Math::PointDistances(mOriginX, mOriginY, *x, *y))
                  {
                     tempX = *x;
                     tempY = *y;
                  }
               }
            }
            // The object being checked is a circle object.
            else if ((*objectIter)->GetObjectType() == Objects::ObjectType::CIRCLE)
            {
               // Check if the ray collides with this circle object.
               if (true == Math::LineCircleCollision(mOriginX, mOriginY,
                                                     mOriginX + mRadius * cos(angleIter->first * Math::RADIANS_CONVERSION),
                                                     mOriginY + mRadius * sin(angleIter->first * Math::RADIANS_CONVERSION),
                                                     dynamic_cast<Objects::CircleObject*>(*objectIter), x, y))
               {
                  if (Math::PointDistances(mOriginX, mOriginY, tempX, tempY) > Math::PointDistances(mOriginX, mOriginY, *x, *y))
                  {
                     tempX = *x;
                     tempY = *y;
                  }
               }
            }
         }
               
         // Check to make sure the distance is not further than the distance of the light's radius.
         float circleMaxDistanceX = mOriginX + mRadius * cos(angleIter->first * Math::RADIANS_CONVERSION);
         float circleMaxDistanceY = mOriginY + mRadius * sin(angleIter->first * Math::RADIANS_CONVERSION);
         if (Math::PointDistances(mOriginX, mOriginY, tempX, tempY) >
             Math::PointDistances(mOriginX, mOriginY,  circleMaxDistanceX, circleMaxDistanceY))
         {
            mPoints.push_back(std::make_pair(angleIter->first, std::make_pair(circleMaxDistanceX, circleMaxDistanceY)));
         }
         // Point is within the lights distance so add the point.
         else
         {
            mPoints.push_back(std::make_pair(angleIter->first, std::make_pair(tempX, tempY)));
         }

         // Reset distance of the point to be furthest away.
         tempX = std::numeric_limits<float>::max();
         tempY = std::numeric_limits<float>::max();
      }

      // Sort the list based on degrees in ascending order.
      std::sort(mPoints.begin(), mPoints.end(), [](auto &left, auto &right)
      {
         return left.first < right.first;
      });

      // Cleanup
      delete x;
      delete y;
      delete ligthCircle;
      delete pCollisionPoints;
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

      // Check to make sure the ray doesn't pass through another object from the origin to the rectangle point.
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
         mAnglesToCheck.push_back(std::make_pair(angleDegrees + 0.1F, true));
         mAnglesToCheck.push_back(std::make_pair(angleDegrees - 0.1F, true));
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
   void Light::CircleCollisionPoints(Objects::CircleObject* aThisCircle,
                                     std::vector<std::pair<float, float>>* apCollisionPoints)
   {  
      // Find the angle from the circle center to the circle edge where the light would pass through with a single collision.
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

      // Add the edge and point close to the edge to possible light points.
      apCollisionPoints->push_back(std::make_pair(cwX, cwY));

      // Find the edge points and angle to the point form the light origin for the counterclockwise angle.
      float ccwSide = angleDegrees - (180.0F - angleCircleToEdge);
      float ccwX = aThisCircle->GetCoordinateX() + aThisCircle->GetRadius()*cos(ccwSide * Math::RADIANS_CONVERSION);
      float ccwY = aThisCircle->GetCoordinateY() + aThisCircle->GetRadius()*sin(ccwSide * Math::RADIANS_CONVERSION);
      
      // Add the edge and point close to the edge to possible light points.
      apCollisionPoints->push_back(std::make_pair(ccwX, ccwY));

      // Find some collision points along the circle between the two edges.
      float cwAngleFromOrigin = angleDegrees + angleOriginToEdge;
      float ccwAngleFromOrigin = angleDegrees - angleOriginToEdge;
      float* x = new float;
      float* y = new float;
      for (float i = ccwAngleFromOrigin + 1.0F; i < cwAngleFromOrigin; i += 2.0F)
      {
         Math::LineCircleCollision(mOriginX, mOriginY,
                                   mOriginX + mRadius*cos(i * Math::RADIANS_CONVERSION), mOriginY + mRadius*sin(i * Math::RADIANS_CONVERSION),
                                   aThisCircle,
                                   x, y);

         apCollisionPoints->push_back(std::make_pair(*x, *y));    
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

   //******************************************************************************************************************
   //
   // Method: RectangleRectangleCollisionPoints
   //
   // Description:
   //    Checks for collision points between two rectangles based on the origin of the light. For example, if the
   //    light is above both rectangles and to the right of the first rectangle then the only two lines needed
   //    to be check for collision is the top horizontal edge of the first rectangle agaisnt the right vertical
   //    edge of the second rectangle as that is the only collision point the light will possiblu reach without passing
   //    through either rectangle.
   //
   // Arguments:
   //    apRectangleOne - One of the rectangle to check for collision points.
   //    apRectangleTwo - The second rectangle to check for collision points.
   //    apCollisionPoints - The collection of possible collision points known to the light source.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::RectangleRectangleCollisionPoints(Objects::RectangleObject* apRectangleOne,
                                                 Objects::RectangleObject* apRectangleTwo,
                                                 std::vector<std::pair<float, float>>* apCollisionPoints)
   {
      Line* rectangleOneHorizontal= nullptr;
      Line* rectangleOneVertical= nullptr;
      Line* rectangleTwoHorizontal= nullptr;
      Line* rectangleTwoVertical= nullptr;

      // check light is left/right of rectangle one.
      if (mOriginX < apRectangleOne->GetCoordinateX())
      {
         rectangleOneVertical = new Line;
         rectangleOneVertical->originX = apRectangleOne->GetCoordinateX();
         rectangleOneVertical->originY = apRectangleOne->GetCoordinateY();
         rectangleOneVertical->endY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
      }
      else if (mOriginX > apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth())
      {
         rectangleOneVertical = new Line;
         rectangleOneVertical->originX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneVertical->originY = apRectangleOne->GetCoordinateY();
         rectangleOneVertical->endX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneVertical->endY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
      }
      // Check Light above/below rectangle one.
      if (mOriginY < apRectangleOne->GetCoordinateY())
      {
         rectangleOneHorizontal = new Line;
         rectangleOneHorizontal->originX = apRectangleOne->GetCoordinateX();
         rectangleOneHorizontal->originY = apRectangleOne->GetCoordinateY();
         rectangleOneHorizontal->endX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneHorizontal->endY = apRectangleOne->GetCoordinateY();
      }
      else if (mOriginY > apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight())
      {
         rectangleOneHorizontal = new Line;
         rectangleOneHorizontal->originX = apRectangleOne->GetCoordinateX();
         rectangleOneHorizontal->originY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
         rectangleOneHorizontal->endX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneHorizontal->endY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
      }

      // check light is left/right of rectangle two.
      if (mOriginX < apRectangleTwo->GetCoordinateX())
      {
         rectangleTwoVertical = new Line;
         rectangleTwoVertical->originX = apRectangleTwo->GetCoordinateX();
         rectangleTwoVertical->originY = apRectangleTwo->GetCoordinateY();
         rectangleTwoVertical->endX = apRectangleTwo->GetCoordinateX();
         rectangleTwoVertical->endY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
      }
      else if (mOriginX > apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth())
      {
         rectangleTwoVertical = new Line;
         rectangleTwoVertical->originX = apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth();
         rectangleTwoVertical->originY = apRectangleTwo->GetCoordinateY();
         rectangleTwoVertical->endX = apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth();
         rectangleTwoVertical->endY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
      }
      // Check Light above/below rectangle two.
      if (mOriginY < apRectangleTwo->GetCoordinateY())
      {
         rectangleTwoHorizontal = new Line;
         rectangleTwoHorizontal->originX = apRectangleTwo->GetCoordinateX();
         rectangleTwoHorizontal->originY = apRectangleTwo->GetCoordinateY();
         rectangleTwoHorizontal->endX = apRectangleTwo->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleTwoHorizontal->endY = apRectangleTwo->GetCoordinateY();
      }
      else if (mOriginY > apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight())
      {
         rectangleTwoHorizontal = new Line;
         rectangleTwoHorizontal->originX = apRectangleTwo->GetCoordinateX();
         rectangleTwoHorizontal->originY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
         rectangleTwoHorizontal->endX = apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth();
         rectangleTwoHorizontal->endY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
      }

      float* x = new float;
      float* y = new float;
      // Check if rectangle one vertical and rectangle two horizontal lines will collide. 
      if (rectangleOneVertical != nullptr)
      {
         if (rectangleTwoHorizontal != nullptr)
         {
            if (Math::LineLineCollision(rectangleOneVertical->originX, rectangleOneVertical->originY,
                                        rectangleOneVertical->endX, rectangleOneVertical->endY,
                                        rectangleTwoHorizontal->originX, rectangleTwoHorizontal->originY,
                                        rectangleTwoHorizontal->endX, rectangleTwoHorizontal->endY,
                                        x, y) == true)
            {
               apCollisionPoints->push_back(std::make_pair(*x, *y));
            }
         }
      }
      // Check if rectangle one horizontal and rectangle two vertical lines will collide. 
      if (rectangleOneHorizontal != nullptr)
      {
         if (rectangleTwoVertical != nullptr)
         {
            if (Math::LineLineCollision(rectangleOneHorizontal->originX, rectangleOneHorizontal->originY,
                                        rectangleOneHorizontal->endX, rectangleOneHorizontal->endY,
                                        rectangleTwoVertical->originX, rectangleTwoVertical->originY,
                                        rectangleTwoVertical->endX, rectangleTwoVertical->endY,
                                        x, y) == true)
            {
               apCollisionPoints->push_back(std::make_pair(*x, *y));
            }
         }
      }

      // Cleanup any allocated memory.
      delete rectangleOneHorizontal;
      delete rectangleOneVertical;
      delete rectangleTwoHorizontal;
      delete rectangleTwoVertical;
      delete x;
      delete y;
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}