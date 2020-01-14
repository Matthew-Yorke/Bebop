//*********************************************************************************************************************
//
// File: SinWaveMotion.h
//
// Description:
//    This class handles the sin wave positioning including the sin wave at an angle.
//
//*********************************************************************************************************************

#ifndef SinWaveMotion_H
#define SinWaveMotion_H

#include "MotionBase.h"
#include "../RotationMatrix2D.h"

namespace Bebop { namespace Math
{
   class SinWaveMotion : public MotionBase
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
      public:

         //************************************************************************************************************
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
         //************************************************************************************************************
         SinWaveMotion(const float aAmplitude, const float aFrequency, const float aSpeed, const float aRotation);

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
         float GetPositionX(const float aTime) const override;

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
         float GetPositionY(const float aTime) const override;

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

      protected:

         // There are currently no public member variables for this class.

      protected:

         // There are currently no protected member variables for this class.

      private:

         // The amplitude of a wave in the sin wave.
         float mAmplitude;

         // The frequency of waves for the sin wave.
         float mFrequency;

         // The speed along the sin wave to move at.
         float mSpeed;

         // Holds a rotation matrix for the sin wave rotation.
         RotationMatrix2D mRotationMatrix;

   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************
   };
}}

#endif // SinWaveMotion_H