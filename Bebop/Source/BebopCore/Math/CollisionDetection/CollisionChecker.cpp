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
                                    Objects::RectangleObject* mpRectangleTwo,
                                    std::vector<Vector2D<float>>* apCollisionPoints)
   {
      if (mpRectangleOne->GetCoordinateX() <= mpRectangleTwo->GetCoordinateX() + mpRectangleTwo->GetWidth() &&
          mpRectangleOne->GetCoordinateX() + mpRectangleOne->GetWidth() >= mpRectangleTwo->GetCoordinateX() &&
          mpRectangleOne->GetCoordinateY() <= mpRectangleTwo->GetCoordinateY() + mpRectangleTwo->GetHeight() &&
          mpRectangleOne->GetCoordinateY() + mpRectangleOne->GetHeight() >= mpRectangleTwo->GetCoordinateY())
      {
         // Gather collision points.
         if (apCollisionPoints != nullptr)
         {
            Vector2D<float>* collisionPoint = new Vector2D<float>(0.0F, 0.0F);

            // Rectangle One Top vs Rectangle Two Top
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetTopRightCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetTopRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Top vs Rectangle Two Left Side
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetTopRightCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetBottomLeftCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Top vs Rectangle Two Right Side
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetTopRightCorner(),
                                  mpRectangleTwo->GetTopRightCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Top vs Rectangle Two Bottom
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetTopRightCorner(),
                                  mpRectangleTwo->GetBottomLeftCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Left vs Rectangle Two Top
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetBottomLeftCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetTopRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Left vs Rectangle Two Left Side
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetBottomLeftCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetBottomLeftCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Left vs Rectangle Two Right Side
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetBottomLeftCorner(),
                                  mpRectangleTwo->GetTopRightCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Left vs Rectangle Two Bottom
            if (LineLineCollision(mpRectangleOne->GetTopLeftCorner(), mpRectangleOne->GetBottomLeftCorner(),
                                  mpRectangleTwo->GetBottomLeftCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Right vs Rectangle Two Top
            if (LineLineCollision(mpRectangleOne->GetTopRightCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetTopRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Right vs Rectangle Two Left Side
            if (LineLineCollision(mpRectangleOne->GetTopRightCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetBottomLeftCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Right vs Rectangle Two Right Side
            if (LineLineCollision(mpRectangleOne->GetTopRightCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetTopRightCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Right vs Rectangle Two Bottom
            if (LineLineCollision(mpRectangleOne->GetTopRightCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetBottomLeftCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Bottom vs Rectangle Two Top
            if (LineLineCollision(mpRectangleOne->GetBottomLeftCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetTopRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Bottom vs Rectangle Two Left Side
            if (LineLineCollision(mpRectangleOne->GetBottomLeftCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetTopLeftCorner(), mpRectangleTwo->GetBottomLeftCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Bottom vs Rectangle Two Right Side
            if (LineLineCollision(mpRectangleOne->GetBottomLeftCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetTopRightCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
            // Rectangle One Bottom vs Rectangle Two Bottom
            if (LineLineCollision(mpRectangleOne->GetBottomLeftCorner(), mpRectangleOne->GetBottomRightCorner(),
                                  mpRectangleTwo->GetBottomLeftCorner(), mpRectangleTwo->GetBottomRightCorner(),
                                  collisionPoint) == true)
            {
               apCollisionPoints->push_back(*collisionPoint);
            }
         }

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
   bool RectangleCircleCollision(Objects::RectangleObject* mpRectangle, Objects::CircleObject* mpCircle)
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
                              Objects::CircleObject* mpCircleTwo,
                              std::vector<Vector2D<float>>* apCollisionPoints)
   {
      // Get the distance from the center of the first circle to the second circle.
      float distanceX = mpCircleOne->GetCoordinateX() - mpCircleTwo->GetCoordinateX();
      float distanceY = mpCircleOne->GetCoordinateY() - mpCircleTwo->GetCoordinateY();
      float distance = sqrt((distanceX*distanceX) + (distanceY*distanceY));

      // Check if the distance found is less than the sum of the two circle's radius and if there is then collision
      // has happened.
      if (distance < mpCircleOne->GetRadius() + mpCircleTwo->GetRadius())
      {
         if (apCollisionPoints != nullptr)
         {
            // Avoid circles that overlap.
            if (distance != 0.0F)
            {
               // Distance from circle one to point perpendiculr to intersection points.
               float a = ((mpCircleOne->GetRadius() * mpCircleOne->GetRadius()) - 
                         (mpCircleTwo->GetRadius() * mpCircleTwo->GetRadius()) +
                         (distance * distance)) /
                         (2.0F * distance);
               // Distance from "a" (above) to one of the intersecition points.
               float h = sqrtf((mpCircleOne->GetRadius() * mpCircleOne->GetRadius()) - (a * a));
               // X and Y coordinate of of point that is perpendicular to the intersectoin points.
               float x2 = mpCircleOne->GetCoordinateX() + a * (mpCircleTwo->GetCoordinateX() - mpCircleOne->GetCoordinateX()) / distance;
               float y2 = mpCircleOne->GetCoordinateY() + a * (mpCircleTwo->GetCoordinateY() - mpCircleOne->GetCoordinateY()) / distance;

               // Gather the X and Y points for botht he intersection points.
               Vector2D<float> x3(x2 + h * (mpCircleTwo->GetCoordinateY() - mpCircleOne->GetCoordinateY()) / distance,
                                  y2 - h * (mpCircleTwo->GetCoordinateX() - mpCircleOne->GetCoordinateX()) / distance);
               Vector2D<float> x4(x2 - h * (mpCircleTwo->GetCoordinateY() - mpCircleOne->GetCoordinateY()) / distance,
                                  y2 + h + (mpCircleTwo->GetCoordinateX() - mpCircleOne->GetCoordinateX()) / distance);

               apCollisionPoints->push_back(x3);
               apCollisionPoints->push_back(x4);
            }
         }

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
   bool LineRectangleCollision(Vector2D<float> aOriginPoint,
                               Vector2D<float> aEndPoint,
                               Objects::RectangleObject* mpRectangle,
                               Vector2D<float>* aCollisionPoint)
   {
      Vector2D<float>* left = new Vector2D<float>(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
      Vector2D<float>* top = new Vector2D<float>(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
      Vector2D<float>* right = new Vector2D<float>(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
      Vector2D<float>* bottom = new Vector2D<float>(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
      bool leftCollided = false;
      bool topCollided = false;
      bool rightCollided = false;
      bool bottomCollided = false;

      if (aOriginPoint.GetComponentX() >= mpRectangle->GetCoordinateX() &&
          aOriginPoint.GetComponentX() <= mpRectangle->GetCoordinateX() + mpRectangle->GetWidth() &&
          aOriginPoint.GetComponentY() >= mpRectangle->GetCoordinateY() &&
          aOriginPoint.GetComponentY() <= mpRectangle->GetCoordinateY() + mpRectangle->GetHeight())
      {
         if (aCollisionPoint != nullptr)
            *aCollisionPoint = aOriginPoint;

         return true;
      }

      // Check line collision on left side of the rectangle.
      if (true == LineLineCollision(aOriginPoint, aEndPoint,
                                    mpRectangle->GetTopLeftCorner(), mpRectangle->GetBottomLeftCorner(),
                                    left))
      {
         leftCollided = true;
      }
      // Check line collision on the top of the rectangle.
      if (true == LineLineCollision(aOriginPoint, aEndPoint,
                                    mpRectangle->GetTopLeftCorner(), mpRectangle->GetTopRightCorner(),
                                    top))
      {
         topCollided = true;
      }
      // Check line collision on the right side of the rectangle.
      if (true == LineLineCollision(aOriginPoint, aEndPoint,
                                    mpRectangle->GetTopRightCorner(), mpRectangle->GetBottomRightCorner(),
                                    right))
      {
         rightCollided = true;
      }
      // Check line collision on the bottom side of the rectangle.
      if (true == LineLineCollision(aOriginPoint, aEndPoint,
                                    mpRectangle->GetBottomLeftCorner(), mpRectangle->GetBottomRightCorner(),
                                    bottom))
      {
         bottomCollided = true;
      }

      // Check if any of sides collided and then find the closest point between all the sides.
      if(leftCollided == true || topCollided == true || rightCollided == true || bottomCollided == true)
      {
         Vector2D<float>* closestPoint = left;
         float closestDistance = PointDistances(aOriginPoint, *closestPoint);

         if (PointDistances(aOriginPoint, *top) < closestDistance)
         {
            closestPoint = top;
            closestDistance = PointDistances(aOriginPoint, *top);
         }
         if (PointDistances(aOriginPoint, *right) < closestDistance)
         {
            closestPoint = right;
            closestDistance = PointDistances(aOriginPoint, *right);
         }
         if (PointDistances(aOriginPoint, *bottom) < closestDistance)
         {
            closestPoint = bottom;
            closestDistance = PointDistances(aOriginPoint, *bottom);
         }

         if (aCollisionPoint != nullptr)
            *aCollisionPoint = *closestPoint;

         delete left;
         delete top;
         delete right;
         delete bottom;

         return true;
      }

      delete left;
      delete top;
      delete right;
      delete bottom;

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
   bool LineCircleCollision(Vector2D<float> aOriginPoint,
                            Vector2D<float> aEndPoint,
                            Objects::CircleObject* apCircle,
                            Vector2D<float>* aCollisionPoint)
   {
      Vector2D<float> circleCenter(apCircle->GetCoordinateX(), apCircle->GetCoordinateY());

      float originCircleDistance = PointDistances(aOriginPoint, apCircle->GetCoordinates());
      // Check if the origin is within the circle.
      if (originCircleDistance <= apCircle->GetRadius())
      {
         if (aCollisionPoint != nullptr)
            *aCollisionPoint = aOriginPoint;

         return true;
      }

      Vector2D<float> endToOrigin = aEndPoint - aOriginPoint;
      Vector2D<float> circleToOrigin = circleCenter - aOriginPoint;
      float a = endToOrigin.GetComponentX() * endToOrigin.GetComponentX() + endToOrigin.GetComponentY() * endToOrigin.GetComponentY();
      float bBy2 = endToOrigin.Dot(circleToOrigin);
      float c = circleToOrigin.Dot(circleToOrigin) - (apCircle->GetRadius() * apCircle->GetRadius());

      float pBy2 = bBy2 / a;
      float q = c / a;

      // Check if there is not intersection from the line and circle.
      float disc = pBy2 * pBy2 - q;
      if (disc < 0.0F)
      {
         aCollisionPoint = nullptr;
         return false;
      }

      // Find the intersetion points of the line and circle.
      float tmpSqrt = sqrtf(disc);
      float abScalingFactor1 = -pBy2 + tmpSqrt;
      float abScalingFactor2 = -pBy2 - tmpSqrt;
      Vector2D<float> p1(aOriginPoint.GetComponentX() - endToOrigin.GetComponentX() * abScalingFactor1,
                         aOriginPoint.GetComponentY() - endToOrigin.GetComponentY() * abScalingFactor1);
      Vector2D<float> p2(aOriginPoint.GetComponentX() - endToOrigin.GetComponentX() * abScalingFactor2,
                         aOriginPoint.GetComponentY() - endToOrigin.GetComponentY() * abScalingFactor2);

      float p1ToOrigin = PointDistances(aOriginPoint, p1);
      float p2ToOrigin = PointDistances(aOriginPoint, p2);

      // Find the closest intersection point to the origin.
      Vector2D<float> closestPoint(0.0F, 0.0F);
      if (p1ToOrigin < p2ToOrigin)
      {
         closestPoint = p1;
      }
      else
      {
         closestPoint = p2;
      }

      float dotProduct = (closestPoint.GetComponentX() - aOriginPoint.GetComponentX()) * (aEndPoint.GetComponentX() - aOriginPoint.GetComponentX()) +
                         (closestPoint.GetComponentY() - aOriginPoint.GetComponentY()) * (aEndPoint.GetComponentY() - aOriginPoint.GetComponentY());
      if (dotProduct < 0.0F)
      {
         return false;
      }

      float squareLengthBA = (aEndPoint.GetComponentX() - aOriginPoint.GetComponentX()) * (aEndPoint.GetComponentX() - aOriginPoint.GetComponentX()) +
                             (aEndPoint.GetComponentY() - aOriginPoint.GetComponentY()) * (aEndPoint.GetComponentY() - aOriginPoint.GetComponentY());
      if (dotProduct > squareLengthBA)
      {
         return false;
      }

      if (aCollisionPoint != nullptr)
         *aCollisionPoint = closestPoint;

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
   bool LineLineCollision(Vector2D<float> aLineOneOriginPoint,
                          Vector2D<float> aLineOneEndPoint,
                          Vector2D<float> aLineTwoOriginPoint,
                          Vector2D<float> aLineTwoEndPoint,
                          Vector2D<float>* aCollisionPoint)
   {
      // Retrieve the orientation possibilities.
      int o1 = Orientation(aLineOneOriginPoint,
                           aLineOneEndPoint,
                           aLineTwoOriginPoint); 
      int o2 = Orientation(aLineOneOriginPoint,
                           aLineOneEndPoint,
                           aLineTwoEndPoint); 
      int o3 = Orientation(aLineTwoOriginPoint,
                           aLineTwoEndPoint,
                           aLineOneOriginPoint);
      int o4 = Orientation(aLineTwoOriginPoint,
                           aLineTwoEndPoint,
                           aLineOneEndPoint);

      // Check if segments intersect, but aren't collinear.
      if (o1 != o2 && o3 != o4)
      {
         // Retrieve the intersection point.
         if (aCollisionPoint != nullptr)
         {
            // Line One represented as a1x +b1y = c1.
            float a1 = aLineOneEndPoint.GetComponentY() - aLineOneOriginPoint.GetComponentY();
            float b1 = aLineOneOriginPoint.GetComponentX() - aLineOneEndPoint.GetComponentX();
            float c1 = a1*aLineOneOriginPoint.GetComponentX() + b1*aLineOneOriginPoint.GetComponentY();

            // Line Two represented as a2x +b2y = c2.
            float a2 = aLineTwoEndPoint.GetComponentY() - aLineTwoOriginPoint.GetComponentY();
            float b2 = aLineTwoOriginPoint.GetComponentX() - aLineTwoEndPoint.GetComponentX();
            float c2 = a2*aLineTwoOriginPoint.GetComponentX() + b2*aLineTwoOriginPoint.GetComponentY();

            float determinant = a1*b2 - a2*b1;

            if (aCollisionPoint != nullptr)
            {
               aCollisionPoint->SetComponentX((b2*c1 - b1*c2)/determinant);
               aCollisionPoint->SetComponentY((a1*c2 - a2*c1)/determinant);
            }
         }

         return true;
      }
      
      // Special Cases 
      // LineOneOriginPoint, LineOneEndPoint, and LineTwoOriginPoint are collinear and LineTwoOriginPoint lies on
      // segment LineOneOriginPoint->LineOneEndPoint. 
      if (o1 == 0 && OnSegment(aLineOneOriginPoint,
                               aLineTwoOriginPoint,
                               aLineOneEndPoint))
      {
         if (aCollisionPoint != nullptr)
            *aCollisionPoint = aLineTwoOriginPoint;

         return true;
      }
      
      // LineOneOriginPoint, LineOneEndPOint, and LineTwoEndPoint are collinear and LineTwoEndPoint lies on segment
      // LineOneOriginPoint->LineOneEndPoint. 
      if (o2 == 0 && OnSegment(aLineOneOriginPoint,
                               aLineTwoEndPoint,
                               aLineOneEndPoint))
      {
         if (aCollisionPoint != nullptr)
            *aCollisionPoint = aLineTwoEndPoint;

         return true;
      }
      
      // LineTwoOriginPoint, LineTwoEndPoint, and LineOneOriginPoint are collinear and LineOneOriginPoint lies on
      // segment LineTwoOriginPoint->LineTwoEndPoint. 
      if (o3 == 0 && OnSegment(aLineTwoOriginPoint, 
                               aLineOneOriginPoint,
                               aLineTwoEndPoint))
      {
         if (aCollisionPoint != nullptr)
            *aCollisionPoint = aLineOneOriginPoint;

         return true;
      }
      
       // LineTwoOriginPoint, LineTwoEndPoint, and LineOneEndPoint are collinear and LineOneEndPoint lies on segment
       // LineTwoOriginPoint->LineTwoEndPoint. 
      if (o4 == 0 && OnSegment(aLineTwoOriginPoint,
                               aLineOneOriginPoint,
                               aLineTwoEndPoint))
      {
         if (aCollisionPoint != nullptr)
            *aCollisionPoint = aLineOneOriginPoint;

         return true;
      }
      
      // Doesn't fall in any of the above cases 
      return false;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float PointDistances(Vector2D<float> aOriginPoint, Vector2D<float> aEndPoint)
   {
      return sqrtf((aEndPoint.GetComponentX() - aOriginPoint.GetComponentX())*(aEndPoint.GetComponentX() - aOriginPoint.GetComponentX()) + 
                   (aEndPoint.GetComponentY() - aOriginPoint.GetComponentY())*(aEndPoint.GetComponentY() - aOriginPoint.GetComponentY()));
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
      int Orientation(Vector2D<float> aPointOne,
                      Vector2D<float> aPointTwo,
                      Vector2D<float> aPointThree)
      {
         int val = static_cast<int>((aPointTwo.GetComponentY() - aPointOne.GetComponentY()) * (aPointThree.GetComponentX() - aPointTwo.GetComponentX()) -
                                    (aPointTwo.GetComponentX() - aPointOne.GetComponentX()) * (aPointThree.GetComponentY() - aPointTwo.GetComponentY()));

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
      bool OnSegment(Vector2D<float> aPointOne,
                     Vector2D<float> aPointTwo,
                     Vector2D<float> aPointThree)
      {
         // Check if point Two lies on line segment One-Three.
         if (aPointTwo.GetComponentX() <= std::max(aPointOne.GetComponentX(), aPointThree.GetComponentX()) &&
             aPointTwo.GetComponentX() >= std::min(aPointOne.GetComponentX(), aPointThree.GetComponentX()) && 
             aPointTwo.GetComponentY() <= std::max(aPointOne.GetComponentY(), aPointThree.GetComponentY()) &&
             aPointTwo.GetComponentY() >= std::min(aPointOne.GetComponentY(), aPointThree.GetComponentY()))
         {
            return true; 
         }
  
         // Point Two does not lie on line segment One->Three.
         return false; 
      }
   }
}}