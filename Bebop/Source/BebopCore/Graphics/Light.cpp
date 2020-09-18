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
   //    aOrigin         - The X-Coordinate and Y-Coordinate of the light origin point.
   //    aRadius         - The radius of the light source.
   //    aLightColor     - The color of the light source.
   //    aLightIntensity - Th intensity of the light itself.
   //    aAngleCenter    - The angle the center of the light is pointed at.
   //    aOffset         - The offset angle for either side from the center the light is directed at.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Light::Light(Math::Vector2D<float> aOrigin, const float aRadius, const Color aLightColor,
                const int aLightIntensity, const int aAngleCenter, const int aOffset) :
      mOrigin(aOrigin), mRadius(aRadius), mLightColor(aLightColor),
      mLightIntensity(aLightIntensity), mAngleCenter(aAngleCenter), mLeftOffsetAngle(aAngleCenter - aOffset),
      mRightOffsetAngle(aAngleCenter + aOffset)
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
      return mOrigin.GetComponentX();
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
      mOrigin.SetComponentX(aCoordinateX);
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
      return mOrigin.GetComponentY();
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
      mOrigin.SetComponentY(aCoordinateY);
   }

   //******************************************************************************************************************
   //
   // Method: SetAngleCenter
   //
   // Description:
   //    Upadres the angle that depicts the center of the light and updates the offsets as well based on the new
   //    center.
   //
   // Arguments:
   //    aAngleCenter - The new center of the angle of the light.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::SetAngleCenter(int aAngleCenter)
   {
      int oldAngleCenter = mAngleCenter;
      mAngleCenter = aAngleCenter;

      int difference = oldAngleCenter - mAngleCenter;
      mLeftOffsetAngle -= difference;
      mRightOffsetAngle -= difference;
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
      Objects::CircleObject* ligthCircle = new Objects::CircleObject(mOrigin, mRadius, nullptr);
      std::vector<Objects::Object*> mObjects;
      std::vector<Math::Vector2D<float>>* pCollisionPoints = new std::vector<Math::Vector2D<float>>;

      // Check which objects will collide with the light and store those objects.
      bool objectLigthCollides = false;
      for (auto objectIterator = aBlockingObjects.begin(); objectIterator != aBlockingObjects.end(); ++objectIterator)
      {
         if ((*objectIterator)->GetObjectType() == Objects::ObjectType::RECTANGLE)
         {
            objectLigthCollides = Math::RectangleCircleCollision(dynamic_cast<Objects::RectangleObject*>(*objectIterator), ligthCircle);
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
                  Math::RectangleRectangleCollision(tempCollideRectangle,
                                                    dynamic_cast<Objects::RectangleObject*>(*overlapCheckIterator),
                                                    pCollisionPoints);
               }
               // The object being checked against is a circle.
               else if ((*overlapCheckIterator)->GetObjectType() == Objects::ObjectType::CIRCLE)
               {
                  Math::RectangleCircleCollision(tempCollideRectangle,
                                                 dynamic_cast<Objects::CircleObject*>(*overlapCheckIterator));
               }
            }

            // Find collision points of circle and rectangle.
            LightRectangleCollisionPoints(tempCollideRectangle, pCollisionPoints);

            // Gather collision points for this rectangle.
            // Top Left
            pCollisionPoints->push_back(tempCollideRectangle->GetTopLeftCorner());
            // Top Right
            pCollisionPoints->push_back(tempCollideRectangle->GetTopRightCorner());
            // Bottom Left
            pCollisionPoints->push_back(tempCollideRectangle->GetBottomLeftCorner());
            // Bottom Right
            pCollisionPoints->push_back(tempCollideRectangle->GetBottomRightCorner());
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
                                                 tempCollideCircle);
               }
               // The object being checked against is a circle.
               else if ((*overlapCheckIterator)->GetObjectType() == Objects::ObjectType::CIRCLE)
               {
                  Math::CircleCircleCollision(dynamic_cast<Objects::CircleObject*>(*collideObjectIterator),
                                              tempCollideCircle,
                                              pCollisionPoints);
               }
            }
            
            // Gather collision points for this circle.
            CircleCollisionPoints(tempCollideCircle, pCollisionPoints);
         }
      }

      // Resolve the found points to see if they can be reached.
      for (auto pointIter = pCollisionPoints->begin(); pointIter != pCollisionPoints->end(); ++pointIter)
      {
         // Get the angle from light origin to the point.
         float angleDegrees = atan2f(pointIter->GetComponentY() - mOrigin.GetComponentY(), pointIter->GetComponentX() - mOrigin.GetComponentX()) * Math::DEGREES_CONVERSION;

         // Make sure the angle being checked is within range of the light.
         if(AngleInBetween(angleDegrees) == true)
         {
            // Change angle to be an angle withing the light range since it will be.
            while (angleDegrees < mLeftOffsetAngle)
            {
               angleDegrees += 360.0F;
            }
            while (angleDegrees > mRightOffsetAngle)
            {
               angleDegrees -= 360.0F;
            }

            // Add checks to close surrounding angles
            mAnglesToCheck.push_back(std::make_pair(angleDegrees - 0.1F, true));
            mAnglesToCheck.push_back(std::make_pair(angleDegrees + 0.1F, true));

            // Handle the case if the point is further than the light's radius.
            Math::Vector2D<float> circleMaxDistance(mOrigin.GetComponentX() + mRadius * cos(angleDegrees * Math::RADIANS_CONVERSION),
                                                    mOrigin.GetComponentY() + mRadius * sin(angleDegrees * Math::RADIANS_CONVERSION));
            if (Math::PointDistances(mOrigin, *pointIter) >
                Math::PointDistances(mOrigin,  circleMaxDistance))
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
                  if (true == Math::LineRectangleCollision(mOrigin,
                                                           *pointIter,
                                                           dynamic_cast<Objects::RectangleObject*>(*iter),
                                                           nullptr))
                  {
                     collidesObject = true;
                     break;
                  }
               }
               // Object being checked for collison is a circle.
               else if ((*iter)->GetObjectType() == Objects::ObjectType::CIRCLE)
               {
                  if (true == Math::LineCircleCollision(mOrigin,
                                                        *pointIter,
                                                        dynamic_cast<Objects::CircleObject*>(*iter),
                                                        nullptr))
                  {
                     collidesObject = true;
                     break;
                  }
               }
            }

            // If the ray  does not collide with an object, then add this to the vector of points for drawing.
            if (collidesObject == false)
            {
               mPoints.push_back(std::make_pair(angleDegrees, *pointIter));
            }
         }
      }

      // Add the angles for the sweeping points.
      for (auto degrees = mLeftOffsetAngle; degrees < mRightOffsetAngle; degrees += 15.0F)
      {
         mAnglesToCheck.push_back(std::make_pair(degrees, false));
      }
      mAnglesToCheck.push_back(std::make_pair(mRightOffsetAngle, false));

      // Sort the angles to check in ascending order and remove duplicates.
      std::sort(mAnglesToCheck.begin(), mAnglesToCheck.end(), [](auto &left, auto &right)
      {
         return left < right;
      });
      mAnglesToCheck.erase(std::unique(mAnglesToCheck.begin(), mAnglesToCheck.end()), mAnglesToCheck.end());

      // Check all angles to be checked
      Math::Vector2D<float>* collisionPoint = new Math::Vector2D<float>(0.0F, 0.0F);
      Math::Vector2D<float> tempPoint(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
      for (auto angleIter = mAnglesToCheck.begin(); angleIter != mAnglesToCheck.end(); ++angleIter)
      {
         // Check the angle for the ray against every object the circle is colliding with.
         for (auto objectIter = mObjects.begin(); objectIter != mObjects.end(); ++objectIter)
         {
            // The object being checked is a rectangle object.
            if ((*objectIter)->GetObjectType() == Objects::ObjectType::RECTANGLE)
            {
               Math::Vector2D<float> rayEndPoint(mOrigin.GetComponentX() + mRadius * cos(angleIter->first * Math::RADIANS_CONVERSION),
                                                 mOrigin.GetComponentY() + mRadius * sin(angleIter->first * Math::RADIANS_CONVERSION));
               // Check if the ray collides with this rectangle object.
               if (true == Math::LineRectangleCollision(mOrigin,
                                                        rayEndPoint,
                                                        dynamic_cast<Objects::RectangleObject*>(*objectIter), collisionPoint))
               {
                  if (Math::PointDistances(mOrigin, tempPoint) > Math::PointDistances(mOrigin, *collisionPoint))
                  {
                     tempPoint = *collisionPoint;
                  }
               }
            }
            // The object being checked is a circle object.
            else if ((*objectIter)->GetObjectType() == Objects::ObjectType::CIRCLE)
            {
               Math::Vector2D<float> rayEndPoint(mOrigin.GetComponentX() + mRadius * cos(angleIter->first * Math::RADIANS_CONVERSION),
                                                 mOrigin.GetComponentY() + mRadius * sin(angleIter->first * Math::RADIANS_CONVERSION));
               // Check if the ray collides with this circle object.
               if (true == Math::LineCircleCollision(mOrigin,
                                                     rayEndPoint,
                                                     dynamic_cast<Objects::CircleObject*>(*objectIter), collisionPoint))
               {
                  if (Math::PointDistances(mOrigin, tempPoint) > Math::PointDistances(mOrigin, *collisionPoint))
                  {
                     tempPoint = *collisionPoint;
                  }
               }
            }
         }
               
         // Check to make sure the distance is not further than the distance of the light's radius.
         Math::Vector2D<float> circleMaxDistance(mOrigin.GetComponentX() + mRadius * cos(angleIter->first * Math::RADIANS_CONVERSION),
                                                 mOrigin.GetComponentY() + mRadius * sin(angleIter->first * Math::RADIANS_CONVERSION));
         if (Math::PointDistances(mOrigin, tempPoint) >
             Math::PointDistances(mOrigin, circleMaxDistance))
         {
            mPoints.push_back(std::make_pair(angleIter->first, circleMaxDistance));
         }
         // Point is within the lights distance so add the point.
         else
         {
            mPoints.push_back(std::make_pair(angleIter->first, tempPoint));
         }

         // Reset distance of the point to be furthest away.
         tempPoint.SetComponentX(std::numeric_limits<float>::max());
         tempPoint.SetComponentY(std::numeric_limits<float>::max());
      }

      // Sort the list based on degrees in ascending order.
      std::sort(mPoints.begin(), mPoints.end(), [](auto &left, auto &right)
      {
         return left.first < right.first;
      });

      // Cleanup
      delete collisionPoint;
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
         // Check if the next item in the vector is not the end, in this case connect the current point and next point.
         auto isNext = iterator + 1;
         if (isNext != mPoints.end())
         {
            auto nextPoint = iterator + 1;
            DrawTriangle(iterator->second, nextPoint->second, aWithColor);
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
   void Light::DrawTriangle(Math::Vector2D<float> aFirstPoint, Math::Vector2D<float> aSecondPoint, const bool aWithColor) const
   {
      float firstDistance = Math::PointDistances(mOrigin, aFirstPoint);
      float secondDistance = Math::PointDistances(mOrigin, aSecondPoint);

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
            {mOrigin.GetComponentX(), mOrigin.GetComponentY(), 0, 0, 0, al_map_rgba(mLightColor.GetRedColor(), mLightColor.GetGreenColor(),
                                                                                    mLightColor.GetBlueColor(), mLightColor.GetAlpha())},
            {aFirstPoint.GetComponentX(), aFirstPoint.GetComponentY(), 0, 0, 0, al_map_rgba(firstRed, firstGreen,
                                                                                            firstBlue, firstAlpha)},
            {aSecondPoint.GetComponentX(), aSecondPoint.GetComponentY(), 0, 0, 0, al_map_rgba(secondRed, secondGreen,
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
            {mOrigin.GetComponentX(), mOrigin.GetComponentY(), 0, 0, 0, al_map_rgba(NO_COLOR, NO_COLOR, NO_COLOR, mLightIntensity)},
            {aFirstPoint.GetComponentX(), aFirstPoint.GetComponentY(), 0, 0, 0, al_map_rgba(0, 0, 0, firstPecentDistance)},
            {aSecondPoint.GetComponentX(), aSecondPoint.GetComponentY(), 0, 0, 0, al_map_rgba(0, 0, 0, secondPecentDistance)},
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
   void Light::RectangleCollisionPoint(Math::Vector2D<float> aRectangleCoordinate, Objects::Object* aThisRectangle)
   {
      // Get distance from the origin of the light to the point on the rectangle.
      float distance = Math::PointDistances(mOrigin, aRectangleCoordinate);

      // Point is outside light radius range.
      if (distance > mRadius)
      {
         return;
      }

      // Check if ray to the point is reachable without passing through the rectangle. Return if it would have to pass
      // through the rectangle.
      // Note: Floor the comparison values to get a close approximation.
      Math::Vector2D<float>* collisionPoint = new Math::Vector2D<float>(0.0F, 0.0F);
      Math::LineRectangleCollision(mOrigin, aRectangleCoordinate, dynamic_cast<Objects::RectangleObject*>(aThisRectangle), collisionPoint);
      float collisionDistance = Math::PointDistances(mOrigin, *collisionPoint);
      if (floor(collisionDistance) < floor(distance))
      {
         return;
      }
      delete collisionPoint;

      // Check to make sure the ray doesn't pass through another object from the origin to the rectangle point.
      if (CheckObjectCollisions(aRectangleCoordinate, aThisRectangle) == false)
      {
         // Get the angle from the light origin to the rectangle point.
         float angleDegrees = atan2f(collisionPoint->GetComponentY() - mOrigin.GetComponentY(), collisionPoint->GetComponentX() - mOrigin.GetComponentX()) * Math::DEGREES_CONVERSION;
         while (angleDegrees < 0.0F)
         {
            angleDegrees += 360.0F;
         }
         while (angleDegrees > 360.0F)
         {
            angleDegrees -= 360.0F;
         }

         // Add the point to the list of points to draw.
         mPoints.push_back(std::make_pair(angleDegrees, aRectangleCoordinate));
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
                                     std::vector<Math::Vector2D<float>>* apCollisionPoints)
   {  
      // Find the angle from the circle center to the circle edge where the light would pass through with a single collision.
      float distance = Math::PointDistances(mOrigin, aThisCircle->GetCoordinates());
      float angleOriginToEdge = asinf(aThisCircle->GetRadius() * sin(90.0F * Math::RADIANS_CONVERSION) / distance) * Math::DEGREES_CONVERSION;
      float angleCircleToEdge = 180.0F - 90.0F - angleOriginToEdge;

      // Get the angle from light origin to the circle center.
      float angleDegrees = atan2f(aThisCircle->GetCoordinateY() - mOrigin.GetComponentY(), aThisCircle->GetCoordinateX() - mOrigin.GetComponentX()) * Math::DEGREES_CONVERSION;
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
      Math::Vector2D<float> cw(aThisCircle->GetCoordinateX() + aThisCircle->GetRadius()*cos(cwSide * Math::RADIANS_CONVERSION),
                               aThisCircle->GetCoordinateY() + aThisCircle->GetRadius()*sin(cwSide * Math::RADIANS_CONVERSION));

      // Add the edge and point close to the edge to possible light points.
      apCollisionPoints->push_back(cw);

      // Find the edge points and angle to the point form the light origin for the counterclockwise angle.
      float ccwSide = angleDegrees - (180.0F - angleCircleToEdge);
      Math::Vector2D<float> ccw(aThisCircle->GetCoordinateX() + aThisCircle->GetRadius()*cos(ccwSide * Math::RADIANS_CONVERSION),
                                aThisCircle->GetCoordinateY() + aThisCircle->GetRadius()*sin(ccwSide * Math::RADIANS_CONVERSION));
      
      // Add the edge and point close to the edge to possible light points.
      apCollisionPoints->push_back(ccw);

      // Find some collision points along the circle between the two edges.
      float cwAngleFromOrigin = angleDegrees + angleOriginToEdge;
      float ccwAngleFromOrigin = angleDegrees - angleOriginToEdge;
      float* x = new float;
      float* y = new float;
      Math::Vector2D<float>* collisionPoint = new Math::Vector2D<float>(0.0F, 0.0F);
      for (float i = ccwAngleFromOrigin + 1.0F; i < cwAngleFromOrigin; i += 2.0F)
      {
         Math::Vector2D<float> rayEndPoint(mOrigin.GetComponentX() + mRadius*cos(i * Math::RADIANS_CONVERSION),
                                           mOrigin.GetComponentY() + mRadius*sin(i * Math::RADIANS_CONVERSION));
         Math::LineCircleCollision(mOrigin,
                                   rayEndPoint,
                                   aThisCircle,
                                   collisionPoint);

         apCollisionPoints->push_back(*collisionPoint);    
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
   bool Light::CheckObjectCollisions(Math::Vector2D<float> aEndPoint, Objects::Object* testingObject)
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
            if (true == Math::LineRectangleCollision(mOrigin,
                                                     aEndPoint,
                                                     dynamic_cast<Objects::RectangleObject*>(*iter),
                                                     nullptr))
            {
               return true;
            }
         }
         // Object check is circular.
         else if ((*iter)->GetObjectType() == Objects::ObjectType::CIRCLE)
         {
            // Check if there is collision against the ray. Collision would mean the ray passed through this object
            // before reaching the reaching the end point.
            if (true == Math::LineCircleCollision(mOrigin,
                                                  aEndPoint,
                                                  dynamic_cast<Objects::CircleObject*>(*iter),
                                                  nullptr))
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
                                                 std::vector<Math::Vector2D<float>>* apCollisionPoints)
   {
      Line* rectangleOneHorizontal= nullptr;
      Line* rectangleOneVertical= nullptr;
      Line* rectangleTwoHorizontal= nullptr;
      Line* rectangleTwoVertical= nullptr;

      // check light is left/right of rectangle one.
      if (mOrigin.GetComponentX() < apRectangleOne->GetCoordinateX())
      {
         rectangleOneVertical = new Line;
         rectangleOneVertical->originX = apRectangleOne->GetCoordinateX();
         rectangleOneVertical->originY = apRectangleOne->GetCoordinateY();
         rectangleOneVertical->endY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
      }
      else if (mOrigin.GetComponentX() > apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth())
      {
         rectangleOneVertical = new Line;
         rectangleOneVertical->originX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneVertical->originY = apRectangleOne->GetCoordinateY();
         rectangleOneVertical->endX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneVertical->endY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
      }
      // Check Light above/below rectangle one.
      if (mOrigin.GetComponentY() < apRectangleOne->GetCoordinateY())
      {
         rectangleOneHorizontal = new Line;
         rectangleOneHorizontal->originX = apRectangleOne->GetCoordinateX();
         rectangleOneHorizontal->originY = apRectangleOne->GetCoordinateY();
         rectangleOneHorizontal->endX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneHorizontal->endY = apRectangleOne->GetCoordinateY();
      }
      else if (mOrigin.GetComponentY() > apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight())
      {
         rectangleOneHorizontal = new Line;
         rectangleOneHorizontal->originX = apRectangleOne->GetCoordinateX();
         rectangleOneHorizontal->originY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
         rectangleOneHorizontal->endX = apRectangleOne->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleOneHorizontal->endY = apRectangleOne->GetCoordinateY() + apRectangleOne->GetHeight();
      }

      // check light is left/right of rectangle two.
      if (mOrigin.GetComponentX() < apRectangleTwo->GetCoordinateX())
      {
         rectangleTwoVertical = new Line;
         rectangleTwoVertical->originX = apRectangleTwo->GetCoordinateX();
         rectangleTwoVertical->originY = apRectangleTwo->GetCoordinateY();
         rectangleTwoVertical->endX = apRectangleTwo->GetCoordinateX();
         rectangleTwoVertical->endY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
      }
      else if (mOrigin.GetComponentX() > apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth())
      {
         rectangleTwoVertical = new Line;
         rectangleTwoVertical->originX = apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth();
         rectangleTwoVertical->originY = apRectangleTwo->GetCoordinateY();
         rectangleTwoVertical->endX = apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth();
         rectangleTwoVertical->endY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
      }
      // Check Light above/below rectangle two.
      if (mOrigin.GetComponentY() < apRectangleTwo->GetCoordinateY())
      {
         rectangleTwoHorizontal = new Line;
         rectangleTwoHorizontal->originX = apRectangleTwo->GetCoordinateX();
         rectangleTwoHorizontal->originY = apRectangleTwo->GetCoordinateY();
         rectangleTwoHorizontal->endX = apRectangleTwo->GetCoordinateX() + apRectangleOne->GetWidth();
         rectangleTwoHorizontal->endY = apRectangleTwo->GetCoordinateY();
      }
      else if (mOrigin.GetComponentY() > apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight())
      {
         rectangleTwoHorizontal = new Line;
         rectangleTwoHorizontal->originX = apRectangleTwo->GetCoordinateX();
         rectangleTwoHorizontal->originY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
         rectangleTwoHorizontal->endX = apRectangleTwo->GetCoordinateX() + apRectangleTwo->GetWidth();
         rectangleTwoHorizontal->endY = apRectangleTwo->GetCoordinateY() + apRectangleTwo->GetHeight();
      }

      Math::Vector2D<float>* collisionPoint = new Math::Vector2D<float>(0.0F, 0.0F);
      // Check if rectangle one vertical and rectangle two horizontal lines will collide. 
      if (rectangleOneVertical != nullptr)
      {
         if (rectangleTwoHorizontal != nullptr)
         {
            Math::Vector2D<float> oneVerticalOrigin(rectangleOneVertical->originX, rectangleOneVertical->originY);
            Math::Vector2D<float> oneVerticalEnd(rectangleOneVertical->endX, rectangleOneVertical->endY);
            Math::Vector2D<float> twoHoriztonalOrigin(rectangleTwoHorizontal->originX, rectangleTwoHorizontal->originY);
            Math::Vector2D<float> twoHoriztonalEnd(rectangleTwoHorizontal->endX, rectangleTwoHorizontal->endY);

            if (Math::LineLineCollision(oneVerticalOrigin, oneVerticalEnd,
                                        twoHoriztonalOrigin, twoHoriztonalEnd,
                                        collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
         }
      }
      // Check if rectangle one horizontal and rectangle two vertical lines will collide. 
      if (rectangleOneHorizontal != nullptr)
      {
         if (rectangleTwoVertical != nullptr)
         {
            Math::Vector2D<float> oneVHoriztonalOrigin(rectangleOneHorizontal->originX, rectangleOneHorizontal->originY);
            Math::Vector2D<float> oneVHoriztonalEnd(rectangleOneHorizontal->endX, rectangleOneHorizontal->endY);
            Math::Vector2D<float> twoVerticalOrigin(rectangleTwoVertical->originX, rectangleTwoVertical->originY);
            Math::Vector2D<float> twoVerticalEnd(rectangleTwoVertical->endX, rectangleTwoVertical->endY);

            if (Math::LineLineCollision(oneVHoriztonalOrigin, oneVHoriztonalEnd,
                                        twoVerticalOrigin, twoVerticalEnd,
                                        collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
         }
      }

      // Cleanup any allocated memory.
      delete rectangleOneHorizontal;
      delete rectangleOneVertical;
      delete rectangleTwoHorizontal;
      delete rectangleTwoVertical;
      delete collisionPoint;
   }

   //******************************************************************************************************************
   //
   // Method: LightRectangleCollisionPoints
   //
   // Description:
   //    Gather points where the outer edge of the light source collides with sides of a rectangle. The only
   //    sides to be checked are closest to the light source itself (e.g., if the light is above and to the left
   //    of the rectangle, only the top and left edge need to be checked for collision points).
   //
   // Arguments:
   //    apRectangle       - Rectangle to check for collision points against the light.
   //    apCollisionPoints - The collection of possible collision points known to the light source.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::LightRectangleCollisionPoints(Objects::RectangleObject* apRectangle,
                                      std::vector<Math::Vector2D<float>>* apCollisionPoints)
   {
      Line* rectangleHorizontal= nullptr;
      Line* rectangleVertical= nullptr;

      // check light is left/right of rectangle one.
      if (mOrigin.GetComponentX() < apRectangle->GetCoordinateX())
      {
         rectangleVertical = new Line;
         rectangleVertical->originX = apRectangle->GetCoordinateX();
         rectangleVertical->originY = apRectangle->GetCoordinateY();
         rectangleVertical->endX = apRectangle->GetCoordinateX();
         rectangleVertical->endY = apRectangle->GetCoordinateY() + apRectangle->GetHeight();
      }
      else if (mOrigin.GetComponentX() > apRectangle->GetCoordinateX() + apRectangle->GetWidth())
      {
         rectangleVertical = new Line;
         rectangleVertical->originX = apRectangle->GetCoordinateX() + apRectangle->GetWidth();
         rectangleVertical->originY = apRectangle->GetCoordinateY();
         rectangleVertical->endX = apRectangle->GetCoordinateX() + apRectangle->GetWidth();
         rectangleVertical->endY = apRectangle->GetCoordinateY() + apRectangle->GetHeight();
      }
      // Check Light above/below rectangle one.
      if (mOrigin.GetComponentY() < apRectangle->GetCoordinateY())
      {
         rectangleHorizontal = new Line;
         rectangleHorizontal->originX = apRectangle->GetCoordinateX();
         rectangleHorizontal->originY = apRectangle->GetCoordinateY();
         rectangleHorizontal->endX = apRectangle->GetCoordinateX() + apRectangle->GetWidth();
         rectangleHorizontal->endY = apRectangle->GetCoordinateY();
      }
      else if (mOrigin.GetComponentY() > apRectangle->GetCoordinateY() + apRectangle->GetHeight())
      {
         rectangleHorizontal = new Line;
         rectangleHorizontal->originX = apRectangle->GetCoordinateX();
         rectangleHorizontal->originY = apRectangle->GetCoordinateY() + apRectangle->GetHeight();
         rectangleHorizontal->endX = apRectangle->GetCoordinateX() + apRectangle->GetWidth();
         rectangleHorizontal->endY = apRectangle->GetCoordinateY() + apRectangle->GetHeight();
      }

      Objects::CircleObject* ligthCircle = new Objects::CircleObject(mOrigin, mRadius, nullptr);
      Math::Vector2D<float>* collisionPoint = new Math::Vector2D<float>(0.0F, 0.0F);

      if (rectangleHorizontal != nullptr)
      {
         LineCircleCollision(Math::Vector2D<float>(rectangleHorizontal->originX, rectangleHorizontal->originY),
                             Math::Vector2D<float>(rectangleHorizontal->endX, rectangleHorizontal->endY),
                             ligthCircle, collisionPoint);
         if (collisionPoint != nullptr)
         {
            apCollisionPoints->push_back(*collisionPoint);
         }
         LineCircleCollision(Math::Vector2D<float>(rectangleHorizontal->endX, rectangleHorizontal->endY),
                             Math::Vector2D<float>(rectangleHorizontal->originX, rectangleHorizontal->originY),
                             ligthCircle, collisionPoint);
         if (collisionPoint != nullptr)
         {
            apCollisionPoints->push_back(*collisionPoint);
         }
      }
      
      if (rectangleVertical != nullptr)
      {
         LineCircleCollision(Math::Vector2D<float>(rectangleVertical->originX, rectangleVertical->originY),
                             Math::Vector2D<float>(rectangleVertical->endX, rectangleVertical->endY),
                             ligthCircle, collisionPoint);
         if (collisionPoint != nullptr)
         {
            apCollisionPoints->push_back(*collisionPoint);
         }
         LineCircleCollision(Math::Vector2D<float>(rectangleVertical->endX, rectangleVertical->endY),
                             Math::Vector2D<float>(rectangleVertical->originX, rectangleVertical->originY),
                             ligthCircle, collisionPoint);
         if (collisionPoint != nullptr)
         {
            apCollisionPoints->push_back(*collisionPoint);
         }
      }

      // Cleanup any allocated memory.
      delete ligthCircle;
      delete rectangleHorizontal;
      delete rectangleVertical;
      delete collisionPoint;
   }

   //******************************************************************************************************************
   //
   // Method: AngleInBetween
   //
   // Description:
   //    Checks if the passed in angle is inbetween the lights left and right offset when normalized.
   //
   // Arguments:
   //    aCheckingAngle - The angle being checked.
   //
   // Return:
   //    True  - The checked angle is inbetween the light's left and right offset angle.
   //    False - The checked angle is not inbetween the light's left and right offset angle.
   //
   //******************************************************************************************************************
   bool Light::AngleInBetween(int aCheckingAngle)
   {
      int normalizedCheckingAngle = (360 + (aCheckingAngle % 360)) % 360;
	   int normalizedLowAngle = (3600000 + mLeftOffsetAngle) % 360;
	   int normalizedHighAngle = (3600000 + mRightOffsetAngle) % 360;

	   if (normalizedLowAngle < normalizedHighAngle)
	   	return normalizedLowAngle <= normalizedCheckingAngle && normalizedCheckingAngle <= normalizedHighAngle;
	   return normalizedLowAngle <= normalizedCheckingAngle || normalizedCheckingAngle <= normalizedHighAngle;
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}