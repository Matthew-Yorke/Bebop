//*********************************************************************************************************************
//
// File: SinWaveMotion.cpp
//
// Description:
//    This class handles the sin wave positioning including the sin wave at an angle.
//
//*********************************************************************************************************************

#include "SinWaveMotion.h"
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
   // Method Name: SinWaveMotion
   //
   // Description:
   //    Constructor that sets default values for member variables.
   //
   // Arguments:
   //    aAmplitude - The amplitude of a wave for the sin wave.
   //    aFrequency - The frequency of the waves fort he sin wave.
   //    aSpeed     - The speed (in pixels) to move along the sin wave at.
   //    aRotation  - The rotation in degrees for the sin wave.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   SinWaveMotion::SinWaveMotion(const float aAmplitude, const float aFrequency, const float aSpeed, const float aRotation) :
      mAmplitude(aAmplitude), mFrequency(aFrequency), mSpeed(aSpeed), mRotationMatrix(aRotation)
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
   float SinWaveMotion::GetPositionX(const float aTime) const
   {
      return (mRotationMatrix.GetRotationMatrix()[0][0] * aTime * mSpeed) +
             (mRotationMatrix.GetRotationMatrix()[0][1] * (mAmplitude * sin(mFrequency * aTime * mSpeed)));
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
   float SinWaveMotion::GetPositionY(const float aTime) const
   {
      return (mRotationMatrix.GetRotationMatrix()[1][0] * aTime * mSpeed) +
             (mRotationMatrix.GetRotationMatrix()[1][1] * (mAmplitude * sin(mFrequency * aTime * mSpeed)));
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