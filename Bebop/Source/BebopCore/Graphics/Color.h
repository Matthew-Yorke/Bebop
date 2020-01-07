//*********************************************************************************************************************
//
// File: Color.h
//
// Description:
//    This class handles holding information on a specific color in an RGB fashion. There is also an alpha (opacity)
//    value correlated with the color.
//
//*********************************************************************************************************************

#ifndef Color_H
#define Color_H

namespace Bebop { namespace Graphics
{
   class Color
   {
   //***************************************************************************************************************
   // Methods - Start
   //***************************************************************************************************************
   
      public:
         
         //************************************************************************************************************
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
         //************************************************************************************************************
         Color(const unsigned int aRed, const unsigned int aGreen, const unsigned int aBlue,
               const unsigned int aAlpha);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void SetRedColor(const unsigned int aRed);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void SetGreenColor(const unsigned int aGreen);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void SetBlueColor(const unsigned int aBlue);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void SetAlpha(const unsigned int aAlpha);
      
         //************************************************************************************************************
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
         //************************************************************************************************************
         unsigned int GetRedColor() const;

         //************************************************************************************************************
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
         //************************************************************************************************************
         unsigned int GetGreenColor() const;

         //************************************************************************************************************
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
         //************************************************************************************************************
         unsigned int GetBlueColor() const;

         //************************************************************************************************************
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
         //************************************************************************************************************
         unsigned int GetAlpha() const;

      protected:
      
         // There are currently no protected methods for this class.
      
      private:
      
         //************************************************************************************************************
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
         //************************************************************************************************************
         int VerifyRange(const unsigned int aValue) const;
      
   //******************************************************************************************************************
   // Methods - End
   //******************************************************************************************************************
   
   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************
   
      public:
      
         // There are currently no public member variables for this class.
      
      protected:
      
         // There are currently no protected member variables for this class.
      
      private:
      
         // The value of the red part of the color.
         unsigned int mRed;
         
         // The value of the green part of the color.
         unsigned int mGreen;

         // The value of the blue part of the color.
         unsigned int mBlue;

         // The value of the alpha (opacity) of the color.
         unsigned int mAlpha;
      
   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Color_H