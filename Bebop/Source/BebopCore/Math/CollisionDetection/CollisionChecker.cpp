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
// TODO: Delete this iostream when no longer needed
#include <iostream>
#include <algorithm>

namespace Bebop { namespace Math
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

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
   bool CollisionChecker::RectangleRectangleCollision(Objects::RectangleObject* mpRectangleOne,
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
   bool CollisionChecker::RectangleCircleCollision(Objects::RectangleObject* mpRectangle,
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

      // Compare the distance found to the radius. If the distance is less than or equal to the radius then there is a collision.
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
   bool CollisionChecker::CircleCircleCollision(Objects::CircleObject* mpCircleOne,
                                                Objects::CircleObject* mpCircleTwo)
   {
      // Get the distance from the center of the first circle to the second circle.
      float distanceX = mpCircleOne->GetCoordinateX() - mpCircleTwo->GetCoordinateX();
      float distanceY = mpCircleOne->GetCoordinateY() - mpCircleTwo->GetCoordinateY();
      float distance = sqrt((distanceX*distanceX) + (distanceY*distanceY));

      // Check if the distance found is less than the sum of the two circle's radius and if there is then collision has happened.
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
   //    Checks line and rectangle collision.
   //
   // Arguments:
   //    aOriginPointX - The origin X-Coordinate of the line being tested.
   //    aOriginPointY - The origin Y-Coordinate of the line being tested. 
   //    aEndPointX    - The end X-Coordinate of the line being tested.
   //    aEndPointY    - The end Y-Coordinate of the line being tested.
   //    mpRectangle   - The rectangle being tested against.
   //
   // Return:
   //    True  - There is collision between the line and rectangle.
   //    False - There is no collision between the line and rectangle.
   //
   //******************************************************************************************************************
   bool CollisionChecker::LineRectangleCollision(float aOriginPointX, float aOriginPointY,
                                                  float aEndPointX, float aEndPointY,
                                                  Objects::RectangleObject* mpRectangle)
   {
      // Check line collision on left side of the rectangle.
      if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                    aEndPointX, aEndPointY,
                                    mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY(),
                                    mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight()))
      {
         return true;
      }
      // Check line collision on the top of the rectangle.
      else if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                         aEndPointX, aEndPointY,
                                         mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY(),
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY()))
      {
         return true;
      }
      // Check line collision on the right side of the rectangle.
      else if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                         aEndPointX, aEndPointY,
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY(),
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight()))
      {
         return true;
      }
      // Check line collision on the bottom side of the rectangle.
      else if (true == LineLineCollision(aOriginPointX, aOriginPointY,
                                         aEndPointX, aEndPointY,
                                         mpRectangle->GetCoordinateX(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight(),
                                         mpRectangle->GetCoordinateX() + mpRectangle->GetWidth(), mpRectangle->GetCoordinateY() + mpRectangle->GetHeight()))
      {
         return true;
      }

      return false;
   }

   //******************************************************************************************************************
   //
   // Method Name: LineLineCollision
   //
   // Description:
   //    Checks two lines for collision.
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
   //
   // Return:
   //    True  - There is collision between both lines.
   //    False - There is no collision between both lines.
   //
   //******************************************************************************************************************
   bool CollisionChecker::LineLineCollision(float aLineOneOriginPointX, float aLineOneOriginPointY,
                                            float aLineOneEndPointX, float aLineOneEndPointY,
                                            float aLineTwoOriginPointX, float aLineTwoOriginPointY,
                                            float aLineTwoEndPointX, float aLineTwoEndPointY)
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

      // General case .
      if (o1 != o2 && o3 != o4)
      {
         return true;
      }
      
      // Special Cases 
      // LineOneOriginPoint, LineOneEndPoint, and LineTwoOriginPoint are collinear and LineTwoOriginPoint lies on
      // segment LineOneOriginPoint->LineOneEndPoint. 
      if (o1 == 0 && OnSegment(aLineOneOriginPointX, aLineOneOriginPointY,
                               aLineTwoOriginPointX, aLineTwoOriginPointY,
                               aLineOneEndPointX, aLineOneEndPointY))
      {
         return true;
      }
      
      // LineOneOriginPoint, LineOneEndPOint, and LineTwoEndPoint are collinear and LineTwoEndPoint lies on segment
      // LineOneOriginPoint->LineOneEndPoint. 
      if (o2 == 0 && OnSegment(aLineOneOriginPointX, aLineOneOriginPointY,
                               aLineTwoEndPointX, aLineTwoEndPointY,
                               aLineOneEndPointX, aLineOneEndPointY))
      {
         return true;
      }
      
      // LineTwoOriginPoint, LineTwoEndPoint, and LineOneOriginPoint are collinear and LineOneOriginPoint lies on
      // segment LineTwoOriginPoint->LineTwoEndPoint. 
      if (o3 == 0 && OnSegment(aLineTwoOriginPointX, aLineTwoOriginPointY, 
                               aLineOneOriginPointX, aLineOneOriginPointY,
                               aLineTwoEndPointX, aLineTwoEndPointY))
      {
         return true;
      }
      
       // LineTwoOriginPoint, LineTwoEndPoint, and LineOneEndPoint are collinear and LineOneEndPoint lies on segment
       // LineTwoOriginPoint->LineTwoEndPoint. 
      if (o4 == 0 && OnSegment(aLineTwoOriginPointX, aLineTwoOriginPointY,
                               aLineOneEndPointX, aLineOneEndPointY,
                               aLineTwoEndPointX, aLineTwoEndPointY))
      {
         return true;
      }
      
      // Doesn't fall in any of the above cases 
      return false;
   }

//*********************************************************************************************************************
// Protected Methods - End
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
   //******************************************************************************************************************
   int CollisionChecker::Orientation(float aPointOneX, float aPointOneY,
                                     float aPointTwoX, float aPointTwoY,
                                     float aPointThreeX, float aPointThreeY)
   {
      int val = static_cast<int>((aPointTwoY - aPointOneY) * (aPointThreeX - aPointTwoX) - (aPointTwoX - aPointOneX) * (aPointThreeY - aPointTwoY));

      // Check if the points are collinear.
      if (val == 0)
      {
         return 0;
      }

      // If the value is larger than 0 the points are in clockwise orientation.
      // Else the value is less than 0 and the points are counterclockwise orientation.
      return (val > 0) ? 1: 2;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   bool CollisionChecker::OnSegment(float aPointOneX, float aPointOneY,
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

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}