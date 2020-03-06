//*********************************************************************************************************************
//
// File: CollisionChecker.cpp
//
// Description:
//    This class handles checking objects for collision. This class does not handle the collision handling, but only
//    simply detection of collisions.
//
//*********************************************************************************************************************

#include "CollisionChecker.h"
#include "../MathConstants.h"
#include "../Vector2D.h"
// TODO: Delete this iostream when no longer needed
#include <iostream>
#include <algorithm>

namespace Bebop { namespace Math
{
   //******************************************************************************************************************
   //
   // Method Name: RectangleRectangleCollision
   //
   // Description:
   //    Constructor that sets default values for member variables.
   //
   // Arguments:
   //    aRotation  - The rotation in degrees.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   bool RectangleRectangleCollision(Objects::RectangleObject* mpRectangleOne,
                                    Objects::RectangleObject* mpRectangleTwo)
   {
      if (mpRectangleOne->GetCoordinateX() < mpRectangleTwo->GetCoordinateX() + mpRectangleTwo->GetWidth() &&
          mpRectangleOne->GetCoordinateX() + mpRectangleOne->GetWidth() > mpRectangleTwo->GetCoordinateX() &&
          mpRectangleOne->GetCoordinateY() < mpRectangleTwo->GetCoordinateY() + mpRectangleTwo->GetHeight() &&
          mpRectangleOne->GetCoordinateY() + mpRectangleOne->GetHeight() > mpRectangleTwo->GetCoordinateY())
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   //******************************************************************************************************************
   //
   // Method Name: RectangleCircleCollision
   //
   // Description:
   //    Checks rectangle and circle objects for collision
   //
   // Arguments:
   //    mpRectangle - The rectangular object to be checked for collision.
   //    mpCircle - The circular object to be checked for collision.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   bool RectangleCircleCollision(Objects::RectangleObject* mpRectangle,
                                 Objects::CircleObject* mpCircle)
   {
      //
      float tempCircleX = mpCircle->GetCoordinateX();
      float tempCircleY = mpCircle->GetCoordinateY();

      // Check if the circle is left of the rectangle.
      if (mpCircle->GetCoordinateX() < mpRectangle->GetCoordinateX())
      {
         tempCircleX = mpRectangle->GetCoordinateX();
      }
      // Check if the circle is right of the rectangle.
      else if (mpCircle->GetCoordinateX() > mpRectangle->GetCoordinateX() + mpRectangle->GetWidth())
      {
         tempCircleX = mpRectangle->GetCoordinateX() + mpRectangle->GetWidth();
      }

      // Check if the circle is above the rectangle.
      if (mpCircle->GetCoordinateY() < mpRectangle->GetCoordinateY())
      {
         tempCircleY = mpRectangle->GetCoordinateY();
      }
      // Check if the circle is below the rectangle.
      else if (mpCircle->GetCoordinateY() > mpRectangle->GetCoordinateY() + mpRectangle->GetHeight())
      {
         tempCircleY = mpRectangle->GetCoordinateY() + mpRectangle->GetHeight();
      }

      // Get the distance from the edge found edge and the circle's center using Pythagorean Theorem
      float distanceX = mpCircle->GetCoordinateX() - tempCircleX;
      float distanceY = mpCircle->GetCoordinateY() - tempCircleY;
      float distance = sqrt((distanceX*distanceX) + (distanceY*distanceY));

      // Compare the distance found to the radius. If the distance is less than or equal to the radius then there is a
      // collision.
      if (distance <= mpCircle->GetRadius())
      {
         return true;
      }

      return false;
   }

   //******************************************************************************************************************
   //
   // Method Name: CircleCircleCollision
   //
   // Description:
   //    Checks two circle objects for collision.
   //
   // Arguments:
   //    mpCircleOne - The first circle object to be checked for collision.
   //    mpCircleTwo - The second circle object to be checked for collision.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   bool CircleCircleCollision(Objects::CircleObject* mpCircleOne,
                              Objects::CircleObject* mpCircleTwo)
   {
      // Get the distance from the center of the first circle to the second circle.
      float distanceX = mpCircleOne->GetCoordinateX() - mpCircleTwo->GetCoordinateX();
      float distanceY = mpCircleOne->GetCoordinateY() - mpCircleTwo->GetCoordinateY();
      float distance = sqrt((distanceX*distanceX) + (distanceY*distanceY));

      // Check if the distance found is less than the sum of the two circle's radius and if there is then collision
      // has happened.
      if (distance < mpCircleOne->GetRadius() + mpCircleTwo->GetRadius())
      {
         return true;
      }

      return false;
   }

   //******************************************************************************************************************
   //
   // Method Name: LineRectangleCollision
   //
   // Description:
   //    Checks line segment and rectangle collision.
   //
   // Arguments:
   //    aOriginPointX - The origin X-Coordinate of the line being tested.
   //    aOriginPointY - The origin Y-Coordinate of the line being tested. 
   //    aEndPointX    - The end X-Coordinate of the line being tested.
   //    aEndPointY    - The end Y-Coordinate of the line being tested.
   //    mpRectangle   - The rectangle being tested against.
   //    aCollisionX   - Pointer for the X-Coordinate of the intersection point.
   //    aCollisionY   - Pointer for the Y-Coordinate of the intersection point.
   //
   // Return:
   //    True  - There is collision between the line segment and rectangle.
   //    False - There is no collision between the line segment and rectangle.
   //
   //******************************************************************************************************************
   bool LineRectangleCollision(float aOriginPointX, float aOriginPointY,
                               float aEndPointX, float aEndPointY,
                               Objects::RectangleObject* mpRectangle,
                               float* aCollisionX, float* aCollisionY)
   {
      float* leftX = new float;
      float* leftY = new float;
      float* topX = new float;
      float* topY = new float;
      float* rightX = new float;
      float* rightY = new float;
      float* bottomX = new float;
      float* bottomY = new float;
      bool leftCollided = false;
      bool topCollided = false;
      bool rightCollided = false;
      bool bottomCollided = false;

      // Check line collision on left side of the rectangle.
      if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                    aEndPointX, aEndPointY,
                                    mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY(),
                                    mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight(),
                                    leftX, leftY))
      {
         leftCollided = true;
      }
      // Check line collision on the top of the rectangle.
      if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                         aEndPointX, aEndPointY,
                                         mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY(),
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY(),
                                         topX, topY))
      {
         topCollided = true;
      }
      // Check line collision on the right side of the rectangle.
      if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                         aEndPointX, aEndPointY,
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY(),
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight(),
                                         rightX, rightY))
      {
         rightCollided = true;
      }
      // Check line collision on the bottom side of the rectangle.
      if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                         aEndPointX, aEndPointY,
                                         mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight(),
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight(),
                                         bottomX, bottomY))
      {
         bottomCollided = true;
      }

      // Check if any of sides collided and then find the closest point between all the sides.
      if(leftCollided == true || topCollided == true || rightCollided == true || bottomCollided == true)
      {
         float* closestPointX = leftX;
         float* closestPointY = leftY;
         float closestDistance = PointDistances(aOriginPointX, aOriginPointY, *closestPointX, *closestPointY);

         if (PointDistances(aOriginPointX, aOriginPointY, *topX, *topY) < closestDistance)
         {
            closestPointX = topX;
            closestPointY = topY;
            closestDistance = PointDistances(aOriginPointX, aOriginPointY, *topX, *topY);
         }
         if (PointDistances(aOriginPointX, aOriginPointY, *rightX, *rightY) < closestDistance)
         {
            closestPointX = topX;
            closestPointY = topY;
            closestDistance = PointDistances(aOriginPointX, aOriginPointY, *rightX, *rightY);
         }
         if (PointDistances(aOriginPointX, aOriginPointY, *bottomX, *bottomY) < closestDistance)
         {
            closestPointX = topX;
            closestPointY = topY;
            closestDistance = PointDistances(aOriginPointX, aOriginPointY, *bottomX, *bottomY);
         }

         *aCollisionX = *closestPointX;
         *aCollisionY = *closestPointY;

         delete leftX;
         delete leftY;
         delete topX;
         delete topY;
         delete rightX;
         delete rightY;
         delete bottomX;
         delete bottomY;

         return true;
      }

      delete leftX;
      delete leftY;
      delete topX;
      delete topY;
      delete rightX;
      delete rightY;
      delete bottomX;
      delete bottomY;

      return false;
   }

   //******************************************************************************************************************
   //
   // Method Name: LineCircleCollision
   //
   // Description:
   //    Checks line segment and circle collision. If there is a collision, the aCollisionX and aCollisionY varaibles
   //    will be updated with the closest collision point (from the origin).
   //
   // Arguments:
   //    aOriginPointX - The origin X-Coordinate of the line being tested.
   //    aOriginPointY - The origin Y-Coordinate of the line being tested. 
   //    aEndPointX    - The end X-Coordinate of the line being tested.
   //    aEndPointY    - The end Y-Coordinate of the line being tested.
   //    apCircle      - The circle being tested against.
   //    aCollisionX   - Pointer for the X-Coordinate of the closest intersection point.
   //    aCollisionY   - Pointer for the Y-Coordinate of the closest intersection point.
   //
   // Return:
   //    True  - There is collision between the line segment and circle.
   //    False - There is no collision between the line segment and circle.
   //
   //******************************************************************************************************************
   bool LineCircleCollision(float aOriginPointX, float aOriginPointY,
                            float aEndPointX, float aEndPointY,
                            Objects::CircleObject* apCircle,
                            float* aCollisionX, float* aCollisionY)
   {
      Vector2D<float> origin(aOriginPointX, aOriginPointY);
      Vector2D<float> end(aEndPointX, aEndPointY);
      Vector2D<float> circleCenter(apCircle->GetCoordinateX(), apCircle->GetCoordinateY());

      float originCircleDistance = PointDistances(aOriginPointX, aOriginPointY, apCircle->GetCoordinateX(), apCircle->GetStartingCoordinateY());
      // Check if the origin is within the circle.
      if (originCircleDistance <= apCircle->GetRadius())
      {
         *aCollisionX = aOriginPointX;
         *aCollisionY = aOriginPointY;

         return true;
      }

      Vector2D<float> endToOrigin = end - origin;
      Vector2D<float> circleToOrigin = circleCenter - origin;
      float a = endToOrigin.GetComponentX() * endToOrigin.GetComponentX() + endToOrigin.GetComponentY() * endToOrigin.GetComponentY();
      float bBy2 = endToOrigin.Dot(circleToOrigin);
      float c = circleToOrigin.Dot(circleToOrigin) - (apCircle->GetRadius() * apCircle->GetRadius());

      float pBy2 = bBy2 / a;
      float q = c / a;

      // Check if there is not intersection from the line and circle.
      float disc = pBy2 * pBy2 - q;
      if (disc < 0.0F)
      {
         return false;
      }

      // Find the intersetion points of the line and circle.
      float tmpSqrt = sqrtf(disc);
      float abScalingFactor1 = -pBy2 + tmpSqrt;
      float abScalingFactor2 = -pBy2 - tmpSqrt;
      Vector2D<float> p1(origin.GetComponentX() - endToOrigin.GetComponentX() * abScalingFactor1,
                         origin.GetComponentY() - endToOrigin.GetComponentY() * abScalingFactor1);
      Vector2D<float> p2(origin.GetComponentX() - endToOrigin.GetComponentX() * abScalingFactor2,
                         origin.GetComponentY() - endToOrigin.GetComponentY() * abScalingFactor2);

      float p1ToOrigin = PointDistances(origin.GetComponentX(), origin.GetComponentY(), p1.GetComponentX(), p1.GetComponentY());
      float p2ToOrigin = PointDistances(origin.GetComponentX(), origin.GetComponentY(), p2.GetComponentX(), p2.GetComponentY());

      // Find the closest intersection point to the origin.
      float closestX;
      float closestY;
      if (p1ToOrigin < p2ToOrigin)
      {
         closestX = p1.GetComponentX();
         closestY = p1.GetComponentY();
      }
      else
      {
         closestX = p2.GetComponentX();
         closestY = p2.GetComponentY();
      }

      // Find out if closest intersection is on the line segment.
      float closestToOriginDistance = PointDistances(origin.GetComponentX(), origin.GetComponentY(), closestX, closestY);
      float endToOriginDistance= PointDistances(origin.GetComponentX(), origin.GetComponentY(), end.GetComponentX(), end.GetComponentY());
      if (closestToOriginDistance > endToOriginDistance)
      {
         return false;
      }

      *aCollisionX = closestX;
      *aCollisionY = closestY;

      return true;
   }

   //******************************************************************************************************************
   //
   // Method Name: LineLineCollision
   //
   // Description:
   //    Checks two line segments for collision.
   //
   // Arguments:
   //    aLineOneOriginPointX - The origin X-Coordinate of the first line being tested.
   //    aLineOneOriginPointY - The origin Y-Coordinate of the first line being tested. 
   //    aLineOneEndPointX    - The end X-Coordinate of the first line being tested.
   //    aLineOneEndPointY    - The end Y-Coordinate of the first line being tested.
   //    aLineTwoOriginPointX - The origin X-Coordinate of the second line being tested.
   //    aLineTwoOriginPointY - The origin Y-Coordinate of the second line being tested. 
   //    aLineTwoEndPointX    - The end X-Coordinate of the second line being tested.
   //    aLineTwoEndPointY    - The end Y-Coordinate of the second line being tested.
   //    aCollisionX          - Pointer for the X-Coordinate of the intersection point.
   //    aCollisionY          - Pointer for the Y-Coordinate of the intersection point.
   //
   // Return:
   //    True  - There is collision between both lines.
   //    False - There is no collision between both lines.
   //
   //******************************************************************************************************************
   bool LineLineCollision(float aLineOneOriginPointX, float aLineOneOriginPointY,
                          float aLineOneEndPointX, float aLineOneEndPointY,
                          float aLineTwoOriginPointX, float aLineTwoOriginPointY,
                          float aLineTwoEndPointX, float aLineTwoEndPointY,
                          float* aCollisionX, float* aCollisionY)
   {
      // Retrieve the orientation possibilities.
      int o1 = Orientation(aLineOneOriginPointX, aLineOneOriginPointY,
                           aLineOneEndPointX, aLineOneEndPointY,
                           aLineTwoOriginPointX, aLineTwoOriginPointY); 
      int o2 = Orientation(aLineOneOriginPointX, aLineOneOriginPointY,
                           aLineOneEndPointX, aLineOneEndPointY,
                           aLineTwoEndPointX, aLineTwoEndPointY); 
      int o3 = Orientation(aLineTwoOriginPointX, aLineTwoOriginPointY,
                           aLineTwoEndPointX, aLineTwoEndPointY,
                           aLineOneOriginPointX, aLineOneOriginPointY);
      int o4 = Orientation(aLineTwoOriginPointX, aLineTwoOriginPointY,
                           aLineTwoEndPointX, aLineTwoEndPointY,
                           aLineOneEndPointX, aLineOneEndPointY);

      // Check if segments intersect, but aren't collinear.
      if (o1 != o2 && o3 != o4)
      {
         // Retrieve the intersection point.
         if (aCollisionX != nullptr && aCollisionY != nullptr)
         {
            // Line One represented as a1x +b1y = c1.
            float a1 = aLineOneEndPointY - aLineOneOriginPointY;
            float b1 = aLineOneOriginPointX - aLineOneEndPointX;
            float c1 = a1*aLineOneOriginPointX + b1*aLineOneOriginPointY;

            // Line Two represented as a2x +b2y = c2.
            float a2 = aLineTwoEndPointY - aLineTwoOriginPointY;
            float b2 = aLineTwoOriginPointX - aLineTwoEndPointX;
            float c2 = a2*aLineTwoOriginPointX + b2*aLineTwoOriginPointY;

            float determinant = a1*b2 - a2*b1;

            *aCollisionX = (b2*c1 - b1*c2)/determinant;
            *aCollisionY = (a1*c2 - a2*c1)/determinant;
         }

         return true;
      }
      
      // Special Cases 
      // LineOneOriginPoint, LineOneEndPoint, and LineTwoOriginPoint are collinear and LineTwoOriginPoint lies on
      // segment LineOneOriginPoint->LineOneEndPoint. 
      if (o1 == 0 && OnSegment(aLineOneOriginPointX, aLineOneOriginPointY,
                               aLineTwoOriginPointX, aLineTwoOriginPointY,
                               aLineOneEndPointX, aLineOneEndPointY))
      {
         if (aCollisionX != nullptr && aCollisionY != nullptr)
         {
            *aCollisionX = aLineTwoOriginPointX;
            *aCollisionY = aLineTwoOriginPointY;
         }

         return true;
      }
      
      // LineOneOriginPoint, LineOneEndPOint, and LineTwoEndPoint are collinear and LineTwoEndPoint lies on segment
      // LineOneOriginPoint->LineOneEndPoint. 
      if (o2 == 0 && OnSegment(aLineOneOriginPointX, aLineOneOriginPointY,
                               aLineTwoEndPointX, aLineTwoEndPointY,
                               aLineOneEndPointX, aLineOneEndPointY))
      {
         if (aCollisionX != nullptr && aCollisionY != nullptr)
         {
            *aCollisionX = aLineTwoEndPointX;
            *aCollisionY = aLineTwoEndPointY;
         }

         return true;
      }
      
      // LineTwoOriginPoint, LineTwoEndPoint, and LineOneOriginPoint are collinear and LineOneOriginPoint lies on
      // segment LineTwoOriginPoint->LineTwoEndPoint. 
      if (o3 == 0 && OnSegment(aLineTwoOriginPointX, aLineTwoOriginPointY, 
                               aLineOneOriginPointX, aLineOneOriginPointY,
                               aLineTwoEndPointX, aLineTwoEndPointY))
      {
         if (aCollisionX != nullptr && aCollisionY != nullptr)
         {
            *aCollisionX = aLineOneOriginPointX;
            *aCollisionY = aLineOneOriginPointY;
         }

         return true;
      }
      
       // LineTwoOriginPoint, LineTwoEndPoint, and LineOneEndPoint are collinear and LineOneEndPoint lies on segment
       // LineTwoOriginPoint->LineTwoEndPoint. 
      if (o4 == 0 && OnSegment(aLineTwoOriginPointX, aLineTwoOriginPointY,
                               aLineOneEndPointX, aLineOneEndPointY,
                               aLineTwoEndPointX, aLineTwoEndPointY))
      {
         if (aCollisionX != nullptr && aCollisionY != nullptr)
         {
            *aCollisionX = aLineOneEndPointX;
            *aCollisionY = aLineOneEndPointY;
         }

         return true;
      }
      
      // Doesn't fall in any of the above cases 
      return false;
   }

   namespace
   {
      //***************************************************************************************************************
      //
      // Method Name: Orientation
      //
      // Description:
      //    Find the orientation between ordered triplet points.
      //
      // Arguments:
      //    aPointOneX   - The origin X-Coordinate of the first point.
      //    aPointOneY   - The origin Y-Coordinate of the first point.
      //    aPointTwoX   - The origin X-Coordinate of the two point.
      //    aPointTwoY   - The origin Y-Coordinate of the two point.
      //    aPointThreeX - The origin X-Coordinate of the three point.
      //    aPointThreeY - The origin Y-Coordinate of the three point.
      //
      // Return:
      //    0 = Points are collinear.
      //    1 = Points are in Clockwise orientation.
      //    2 = Points are in Counterclockwise orientation.
      //
      //***************************************************************************************************************
      int Orientation(float aPointOneX, float aPointOneY,
                      float aPointTwoX, float aPointTwoY,
                      float aPointThreeX, float aPointThreeY)
      {
         int val = static_cast<int>((aPointTwoY - aPointOneY) * (aPointThreeX - aPointTwoX) -
                                    (aPointTwoX - aPointOneX) * (aPointThreeY - aPointTwoY));

         // Check if the points are collinear.
         if (val == 0)
         {
            return 0;
         }

         // If the value is larger than 0 the points are in clockwise orientation.
         // Else the value is less than 0 and the points are counterclockwise orientation.
         return (val > 0) ? 1: 2;
      }

      //***************************************************************************************************************
      //
      // Method Name: OnSegment
      //
      // Description:
      //    Given three collinear points (One, two, and Three), this function checks if point Two lies on line segment
      //    One->Three.
      //
      // Arguments:
      //    aPointOneX   - The origin X-Coordinate of the first point.
      //    aPointOneY   - The origin Y-Coordinate of the first point.
      //    aPointTwoX   - The origin X-Coordinate of the two point.
      //    aPointTwoY   - The origin Y-Coordinate of the two point.
      //    aPointThreeX - The origin X-Coordinate of the three point.
      //    aPointThreeY - The origin Y-Coordinate of the three point.
      //
      // Return:
      //    True  - Point Two lies on line segment One->Three.
      //    False - Point Two does not lie on line segment One->Three.
      //
      //***************************************************************************************************************
      bool OnSegment(float aPointOneX, float aPointOneY,
                     float aPointTwoX, float aPointTwoY,
                     float aPointThreeX, float aPointThreeY)
      {
         // Check if point Two lies on line segment One-Three.
         if (aPointTwoX <= std::max(aPointOneX, aPointThreeX) &&
             aPointTwoX >= std::min(aPointOneX, aPointThreeX) && 
             aPointTwoY <= std::max(aPointOneY, aPointThreeY) &&
             aPointTwoY >= std::min(aPointOneY, aPointThreeY))
         {
            return true; 
         }
  
         // Point Two does not lie on line segment One->Three.
         return false; 
      }

      //***************************************************************************************************************
      //
      // Method Name: PointDistances
      //
      // Description:
      //    Returns the coordinates for the collision of two lines (One and Two).
      //
      // Arguments:
      //    aOriginPointX - The origin X-Coordinate of the distance being tested.
      //    aOriginPointY - The origin Y-Coordinate of the distance being tested. 
      //    aEndPointX    - The end X-Coordinate of the distance being tested.
      //    aEndPointY    - The end Y-Coordinate of the distance being tested.
      //
      // Return:
      //    Returns the distances between two points.
      //
      //***************************************************************************************************************
      float PointDistances(float aOriginPointX, float aOriginPointY, float aEndPointX, float aEndPointY)
      {
         return sqrtf((aEndPointX - aOriginPointX)*(aEndPointX - aOriginPointX) + 
                      (aEndPointY - aOriginPointY)*(aEndPointY - aOriginPointY));
      }
   }
}}