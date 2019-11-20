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
   // Method Name: InsertRectangleObject
   //
   // Description:
   //    Insert a rectangle object to check for collisions.
   //
   // Arguments:
   //    mpRectangleObject - The rectangle object to be inserted for collision checks.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void CollisionChecker::InsertRectangleObject(Objects::RectangleObject* mpRectangleObject)
   {
      mpRectangularObjects.push_back(mpRectangleObject);
   }

   //******************************************************************************************************************
   //
   // Method Name: CheckCollision
   //
   // Description:
   //    Checks all the objects for collisions.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void CollisionChecker::CheckCollision()
   {
      // If  there aren't enough objects in the vector, return as there is no collisions to checks.
      if (mpRectangularObjects.size() >= MINIMUM_COLLISION_VECTOR_SIZE)
      {
         // Check rectangle objects against each other.
         for (auto startRectIterator = mpRectangularObjects.begin();
              startRectIterator != mpRectangularObjects.end();
              ++startRectIterator)
         {
            // Start collision check against every object after the start rectangle object.
            for (auto potentialCollisionIterator = startRectIterator + NEXT_ITERATOR_VALUE;
                 potentialCollisionIterator != mpRectangularObjects.end();
                 ++potentialCollisionIterator)
            {
               // TODO: This string is temporary to just check for collision until collision handling is implemented.
               std::cout << "Start(" << std::distance(mpRectangularObjects.begin(), startRectIterator) << ") End(" <<
               std::distance(mpRectangularObjects.begin(), potentialCollisionIterator) << ") Collision: " <<
               std::boolalpha << HasCollided(*startRectIterator, *potentialCollisionIterator) << std::endl;
            }
         }

         // TODO: Remove this string when collision handling is implemented.
         std::cout << "----------------------------------------------------------------------\n";
      }
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
   // Method Name: HasCollided
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
   bool CollisionChecker::HasCollided(Objects::RectangleObject* mpRectangleOne, Objects::RectangleObject* mpRectangleTwo)
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

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}