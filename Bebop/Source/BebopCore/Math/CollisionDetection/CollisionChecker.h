//*********************************************************************************************************************
//
// File: CollisionChecker.h
//
// Description:
//    This class handles creating a rotation matrix for 2D objects.
//
//*********************************************************************************************************************

#ifndef CollisionChecker_H
#define CollisionChecker_H

#include "..\..\Objects\RectangleObject.h"

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
		   //************************************************************************************************************
		   CollisionChecker();

         //************************************************************************************************************
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
		   //************************************************************************************************************
         bool HasCollided(Objects::RectangleObject* mpRectangleOne, Objects::RectangleObject* mpRectangleTwo);

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