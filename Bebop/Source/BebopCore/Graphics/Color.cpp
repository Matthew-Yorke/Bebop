//*********************************************************************************************************************
//
// File: Color.cpp
//
// Description:
//    This class handles holding information on a specific color in an RGB fashion. There is also an alpha (opacity)
//    value correlated with the color.  
//
//*********************************************************************************************************************

#include "Color.h"
#include "GraphicsConstants.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Scene
   //
   // Description:
   //    Constructor for a color that sets the red, green, blue, and alpha properties.
   //
   // Arguments:
   //    aRed   - The red color value.
   //    aGreen - The green color value.
   //    aBlue  - The blue color value.
   //    aAlpha - The alpha (opacity) value.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Color::Color(const unsigned int aRed, const unsigned int aGreen, const unsigned int aBlue,
                const unsigned int aAlpha) :
      mRed(VerifyRange(aRed)), mBlue(VerifyRange(aBlue)), mGreen(VerifyRange(aGreen)), mAlpha(VerifyRange(aAlpha))
   {
   }

   //******************************************************************************************************************
   //
   // Method: SetRedColor
   //
   // Description:
   //    Sets a new red color value.
   //
   // Arguments:
   //    aRed - The red color value.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Color::SetRedColor(const unsigned int aRed)
   {
      mRed = VerifyRange(aRed);
   }

   //******************************************************************************************************************
   //
   // Method: SetGreenColor
   //
   // Description:
   //    Sets a new green color value.
   //
   // Arguments:
   //    aGreen - The green color value.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Color::SetGreenColor(const unsigned int aGreen)
   {
      mGreen = VerifyRange(aGreen);
   }

   //******************************************************************************************************************
   //
   // Method: SetBlueColor
   //
   // Description:
   //    Sets a new blue color value.
   //
   // Arguments:
   //    aBlue - The blue color value.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Color::SetBlueColor(const unsigned int aBlue)
   {
      mBlue = VerifyRange(aBlue);
   }

   //******************************************************************************************************************
   //
   // Method: SetAlpha
   //
   // Description:
   //    Sets a new alpha (opacity) value.
   //
   // Arguments:
   //    aAlpha - The alpha (opacity) value.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Color::SetAlpha(const unsigned int aAlpha)
   {
      mAlpha = VerifyRange(aAlpha);
   }

   //******************************************************************************************************************
   //
   // Method: GetRedColor
   //
   // Description:
   //    Returns the red color value.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the red color value.
   //
   //******************************************************************************************************************
   unsigned int Color::GetRedColor() const
   {
      return mRed;
   }
   
   //******************************************************************************************************************
   //
   // Method: SetGreenColor
   //
   // Description:
   //    Returns the green color value.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the green color value.
   //
   //******************************************************************************************************************
   unsigned int Color::GetGreenColor() const
   {
      return mGreen;
   }
   
   //******************************************************************************************************************
   //
   // Method: GetBlueColor
   //
   // Description:
   //    Returns the blue color value.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the blue color value.
   //
   //******************************************************************************************************************
   unsigned int Color::GetBlueColor() const
   {
      return mBlue;
   }
   
   //******************************************************************************************************************
   //
   // Method: GetAlpha
   //
   // Description:
   //    Returns the alpha (opacity) value.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the alpha (opacity) value.
   //
   //******************************************************************************************************************
   unsigned int Color::GetAlpha() const
   {
      return mAlpha;
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - Start
//*********************************************************************************************************************

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Private Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: VerifyRange
   //
   // Description:
   //    Checks if the value is within the color range. If it is not, then the maximum value is set in its place.
   //
   // Arguments:
   //    aValue - The value being checked to be within the color range.
   //
   // Return:
   //    Returns the finalized color value.
   //
   //******************************************************************************************************************
   int Color::VerifyRange(const unsigned int aValue) const
   {
      if (aValue > MAX_COLOR_VALUE)
      {
         return MAX_COLOR_VALUE;
      }

      return aValue;
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}