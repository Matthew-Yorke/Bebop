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
#include "../../Objects/CircleObject.h"
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
		   // Method Name: RectangleRectangleCollision
		   //
		   // Description:
		   //    Checks two rectangular objects for collision.
		   //
		   // Arguments:
		   //    mpRectangleOne - The first rectangular object to be checked for collision.
         //    mpRectangleTwo - The second rectangular object to be checked for collision.
		   //
		   // Return:
		   //    N/A
		   //
		   //************************************************************************************************************
         bool RectangleRectangleCollision(Objects::RectangleObject* mpRectangleOne,
                                          Objects::RectangleObject* mpRectangleTwo);

         //************************************************************************************************************
		   //
		   // Method Name: RectangleCircleCollision
		   //
		   // Description:
		   //    Checks rectangle and circle objects for collision.
		   //
		   // Arguments:
		   //    mpRectangle - The rectangular object to be checked for collision.
         //    mpCircle - The circular object to be checked for collision.
		   //
		   // Return:
		   //    N/A
		   //
		   //************************************************************************************************************
         bool RectangleCircleCollision(Objects::RectangleObject* mpRectangle, Objects::CircleObject* mpCircle);

         //************************************************************************************************************
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
		   //************************************************************************************************************
         bool CircleCircleCollision(Objects::CircleObject* mpCircleOne, Objects::CircleObject* mpCircleTwo);

	   protected:
	
	      // There are currently no protected methods for this class.
	
	   private:
	
	      // There are currently no private methods for this class.
	
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
	
         // There are currently no private member variables for this class.
	
	//******************************************************************************************************************
	// Member Variables - Start
	//******************************************************************************************************************
	};
}}

#endif // CollisionChecker_H