//*********************************************************************************************************************
//
// File: SinWave.cpp
//
// Description:
//    This class handles the sin wave positioning including the sin wave at an angle.
//
//*********************************************************************************************************************

#include "SinWave.h"
#include <allegro5/allegro_primitives.h>
#define _USE_MATH_DEFINES
#include <cmath>

namespace Bebop { namespace Math
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method Name: SinWave
   //
   // Description:
   //    Constructor that sets default values for member variables.
   //
   // Arguments:
   //    aAmplitude - The amplitude of a wave for the sin wave.
   //    aFrequency - The frequency of the waves fort he sin wave.
   //    aRotation  - The rotation in degrees for the sin wave.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   SinWave::SinWave(const float aAmplitude, const float aFrequency, const float aRotation) :
      mAmplitude(aAmplitude), mFrequency(aFrequency), mRotationMatrix(aRotation)
   {
   }

   //************************************************************************************************************
   //
   // Method Name: GetPositionX
   //
   // Description:
   //    This method returns the X-Coordinate position based on the passed in time value.
   //
   // Arguments:
   //    aTime - The time position for the sin wave.
   //
   // Return:
   //    Returns the X-Coordinate.
   //
   //************************************************************************************************************
   float SinWave::GetPositionX(const float aTime)
   {
      return (mRotationMatrix.GetRotationMatrix()[0][0] * aTime) +
             (mRotationMatrix.GetRotationMatrix()[0][1] * (mAmplitude * sin(mFrequency * aTime)));
   }

   //************************************************************************************************************
   //
   // Method Name: GetPositionY
   //
   // Description:
   //    This method returns the Y-Coordinate position based on the passed in time value.
   //
   // Arguments:
   //    aTime - The time position for the sin wave.
   //
   // Return:
   //    Returns the Y-Coordinate.
   //
   //************************************************************************************************************
   float SinWave::GetPositionY(const float aTime)
   {
      return (mRotationMatrix.GetRotationMatrix()[1][0] * aTime) +
             (mRotationMatrix.GetRotationMatrix()[1][1] * (mAmplitude * sin(mFrequency * aTime)));
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