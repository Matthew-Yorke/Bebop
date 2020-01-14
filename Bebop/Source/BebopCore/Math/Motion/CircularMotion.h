//*********************************************************************************************************************
//
// File: CircularMotion.h
//
// Description:
//    This class handles the circular motion, calculating based on the time where the object X and Y positions are.
//
//*********************************************************************************************************************

#ifndef CircularMotion_H
#define CircularMotion_H

#include "MotionBase.h"

namespace Bebop { namespace Math
{
   class CircularMotion : public MotionBase
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
      public:

         //************************************************************************************************************
         //
         // Method Name: CircularMotion
         //
         // Description:
         //    Constructor that sets default values for member variables.
         //
         // Arguments:
         //    aRadius            - The radius of the circular motion.
         //    aRotationPerSecond - The number of rotations/second for the circular motion.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         CircularMotion(const float aRadius, const float aRotationPerSecond);

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

         // The radius of the circular motion.
         float mRadius;

         // The number of rotation per second for the circular motion.
         float mRotationsPerSecond;

   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************
   };
}}

#endif // CircularMotion_H