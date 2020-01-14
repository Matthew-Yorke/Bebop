//*********************************************************************************************************************
//
// File: CircularMotion.cpp
//
// Description:
//    This class handles the circular motion, calculating based on the time where the object X and Y positions are.
//
//*********************************************************************************************************************

#include "CircularMotion.h"
#include "../MathConstants.h"

namespace Bebop { namespace Math
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   CircularMotion::CircularMotion(const float aRadius, const float aRotationsPerSecond) :
      mRadius(aRadius), mRotationsPerSecond(aRotationsPerSecond)
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
   //    aTime - The time position for the circular motion.
   //
   // Return:
   //    Returns the X-Coordinate.
   //
   //************************************************************************************************************
   float CircularMotion::GetPositionX(const float aTime) const
   {
      float angleRadians = (mRotationsPerSecond * CIRCLE_RADIANS) * aTime;
      return cos(angleRadians) * mRadius;
   }
   
   //************************************************************************************************************
   //
   // Method Name: GetPositionY
   //
   // Description:
   //    This method returns the Y-Coordinate position based on the passed in time value.
   //
   // Arguments:
   //    aTime - The time position for the circular motion.
   //
   // Return:
   //    Returns the Y-Coordinate.
   //
   //************************************************************************************************************
   float CircularMotion::GetPositionY(const float aTime) const
   {
      float angleRadians = (mRotationsPerSecond * CIRCLE_RADIANS) * aTime;
      return sin(angleRadians) * mRadius;
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