//*********************************************************************************************************************
//
// File: RotationMatrix2D.h
//
// Description:
//    This class handles creating a rotation matrix for 2D objects.
//
//*********************************************************************************************************************

#ifndef RotationMatrix_H
#define RotationMatrix_H

namespace Bebop { namespace Math
{
	class RotationMatrix2D
	{
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
      
	   public:
	
		   //************************************************************************************************************
		   //
		   // Method Name: RotationMatrix2D
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
		   RotationMatrix2D(const float aRotation);

		   //************************************************************************************************************
		   //
		   // Method Name: ~RotationMatrix2D
		   //
		   // Description:
		   //    Destructor to free memory being used in this class.
		   //
		   // Arguments:
		   //    N/A
		   //
		   // Return:
		   //    N/A
		   //
		   //************************************************************************************************************
		   ~RotationMatrix2D();

		   //************************************************************************************************************
		   //
		   // Method Name: SetAngle
		   //
		   // Description:
		   //    Updates the rotation matrix with a new angle.
		   //
		   // Arguments:
		   //    aRotation  - The rotation in degrees.
		   //
		   // Return:
		   //    N/A
		   //
		   //************************************************************************************************************
		   void SetAngle(const float aRotation);

		   //************************************************************************************************************
		   //
		   // Method Name: GetRotationMatrix
		   //
		   // Description:
		   //    This method returns the rotation matrix.
		   //
		   // Arguments:
		   //    N/A
		   //
		   // Return:
		   //    Returns the rotation matrix.
		   //
		   //************************************************************************************************************
		   float** GetRotationMatrix() const;
	
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
	
		   // Holds the rotation matrix:
		   float** mRotationMatrix;
	
	//******************************************************************************************************************
	// Member Variables - Start
	//******************************************************************************************************************
	};
}}

#endif // RotationMatrix_H