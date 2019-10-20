//*********************************************************************************************************************
//
// File: SinWave.cpp
//
// Description:
//    This class handles the sin wave positioning including the sin wave at an angle.
//
//*********************************************************************************************************************

#include "RotationMatrix2D.h"
#define _USE_MATH_DEFINES
#include <cmath>

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
      mRotationMatrix = new float*[2];
      for (auto i = 0; i < 2; ++i)
      {
         mRotationMatrix[i] = new float[2];
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
         for (auto i = 0; i < 2; i++)
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
      mRotationMatrix[0][0] = cos(aRotation * M_PI / 180.0F);
      mRotationMatrix[0][1] = -sin(aRotation * M_PI / 180.0F);
      mRotationMatrix[1][0] = sin(aRotation * M_PI / 180.0F);
      mRotationMatrix[1][1] = cos(aRotation * M_PI / 180.0F);
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
   float** RotationMatrix2D::GetRotationMatrix()
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