//*********************************************************************************************************************
//
// File: SinWave.h
//
// Description:
//    This class handles the sin wave positioning including the sin wave at an angle.
//
//*********************************************************************************************************************

#ifndef SinWave_H
#define SinWave_H

namespace Bebop { namespace Math
{
   class SinWave
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
      public:

         //************************************************************************************************************
         //
         // Method Name: SinWave
         //
         // Description:
         //    This method returns the current X-Coordinate of the object.
         //
         // Arguments:
         //    aAmplitude - The amplitude of a wave for the sin wave.
         //    aFrequency - The frequency of the waves fort he sin wave.
         //    aRotation  - The rotation in degrees for the sin wave.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         SinWave(const float aAmplitude, const float aFrequency, const float aRotation);

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
         float GetPositionX(const float aTime);

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
         float GetPositionY(const float aTime);

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

         // The amplitude of a wave in the sin wave.
         float mAmplitude;

         // The frequency of waves for the sin wave.
         float mFrequency;

         // Holds the rotation matrix:
         // TODO: This should be moved somewhere else as it may be used for other calculations.
         float mRotationMatrix[2][2];

   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************
   };
}}

#endif // SinWave_H