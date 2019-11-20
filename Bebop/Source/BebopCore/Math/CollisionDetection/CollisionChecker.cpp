//*********************************************************************************************************************
//
// File: CollisionChecker.cpp
//
// Description:
//    This class handles creating a rotation matrix for 2D objects.
//
//*********************************************************************************************************************

#include "CollisionChecker.h"

namespace Bebop { namespace Math
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method Name: CollisionChecker
   //
   // Description:
   //    Constructor that sets default values for member variables.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   CollisionChecker::CollisionChecker()
   {
   }

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