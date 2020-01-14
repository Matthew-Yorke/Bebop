//*********************************************************************************************************************
//
// File: MotionBase.h
//
// Description:
//    This class is the base for all motion classes, forcing anything the inherits it to implement its methods.
//
//*********************************************************************************************************************

#ifndef MotionBase_H
#define MotionBase_H

namespace Bebop { namespace Math
{
   class MotionBase
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
      public:

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
         virtual float GetPositionX(const float aTime) const = 0;

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
         virtual float GetPositionY(const float aTime) const = 0;

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

         // There are currently no private member variables for this class.

   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************
   };
}}

#endif // CircularMotion_H