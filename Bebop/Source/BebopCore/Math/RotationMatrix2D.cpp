//*********************************************************************************************************************
//
// File: RotationMatrix2D.cpp
//
// Description:
//    This class handles creating a rotation matrix for 2D objects.
//
//*********************************************************************************************************************

#include "RotationMatrix2D.h"
#include "MathConstants.h"

namespace Bebop { namespace Math
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   RotationMatrix2D::RotationMatrix2D(const float aRotation)
   {
      mRotationMatrix = new float*[MATRIX_SIZE_2D];
      for (auto i = 0; i < MATRIX_SIZE_2D; ++i)
      {
         mRotationMatrix[i] = new float[MATRIX_SIZE_2D];
      }

      SetAngle(aRotation);
   }

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
   RotationMatrix2D::~RotationMatrix2D()
   {
      if (mRotationMatrix)
      {
         for (auto i = 0; i < MATRIX_SIZE_2D; i++)
         {
            if (mRotationMatrix[i])
            {
               delete[] mRotationMatrix[i];
            }
         }
         delete[] mRotationMatrix;
      }
   }

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
   void RotationMatrix2D::SetAngle(const float aRotation)
   {
      // Rotation Matrix[Row][Column]
      //       0             1
      // 0 | cos(theta)   -sin(theta) |
      // 1 | sin(theta)   cos(theta)  |
      mRotationMatrix[0][0] = cos(aRotation * RADIANS_CONVERSION);
      mRotationMatrix[0][1] = -sin(aRotation * RADIANS_CONVERSION);
      mRotationMatrix[1][0] = sin(aRotation * RADIANS_CONVERSION);
      mRotationMatrix[1][1] = cos(aRotation * RADIANS_CONVERSION);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float** RotationMatrix2D::GetRotationMatrix() const
   {
      return mRotationMatrix;
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