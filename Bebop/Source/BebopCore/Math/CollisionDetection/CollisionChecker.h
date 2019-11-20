//*********************************************************************************************************************
//
// File: CollisionChecker.h
//
// Description:
//    This class handles checking objects for collision. This class does not handle the collision handling, but only
//    simply detection of collisions.
//
//*********************************************************************************************************************

#ifndef CollisionChecker_H
#define CollisionChecker_H

#include "../../Objects/RectangleObject.h"
#include <vector>

namespace Bebop { namespace Math
{
	class CollisionChecker
	{
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
      
	   public:

         //************************************************************************************************************
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
		   //************************************************************************************************************
         void InsertRectangleObject(Objects::RectangleObject* mpRectangleObject);

         //************************************************************************************************************
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
		   //************************************************************************************************************
         void CheckCollision();

	   protected:
	
	      // There are currently no protected methods for this class.
	
	   private:
	
	      //************************************************************************************************************
		   //
		   // Method Name: HasCollided
		   //
		   // Description:
		   //    Checks two rectangular objects for collision
		   //
		   // Arguments:
		   //    mpRectangleOne - The first rectangular object to be checked for collision.
         //    mpRectangleTwo - The second rectangular object to be checked for collision.
		   //
		   // Return:
		   //    N/A
		   //
		   //************************************************************************************************************
         bool HasCollided(Objects::RectangleObject* mpRectangleOne, Objects::RectangleObject* mpRectangleTwo);
	
   //******************************************************************************************************************
   // Methods - End
   //******************************************************************************************************************

   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************
	
      public:

         // There are currently no public member variables for this class.

      protected:
	
	      // There are currently no protected member variables for this class.
	
	   private:
	
         // Vector the holds all the rectangle objects to be used for collision checking.
		   std::vector<Objects::RectangleObject*> mpRectangularObjects;
	
	//******************************************************************************************************************
	// Member Variables - Start
	//******************************************************************************************************************
	};
}}

#endif // CollisionChecker_H