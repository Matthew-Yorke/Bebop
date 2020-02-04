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

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}