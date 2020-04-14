//*********************************************************************************************************************
//
// File: RectangleObject.h
//
// Description:
//    This class handles the functionality for a rectangular object.   
//
//*********************************************************************************************************************

#ifndef RectangleObject_h
#define RectangleObject_h

#include "Object.h"

namespace Bebop { namespace Objects
{
   class RectangleObject : public Object
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
   
      public:
      
         //************************************************************************************************************
         //
         // Method Name: RectangleObject
         //
         // Description:
         //    Constructor that sets default values for member variables.
         //
         // Arguments:
         //    aCoordinateX  - The X-Coordinate the rectangular object is to be displayed on the window.
         //    aCoordinateY  - The Y-Coordinate the rectangular object is to be displayed on the window. 
         //    aWidth        - The width of the rectangular object.
         //    aHeight       - The height of the rectangular object.
         //    aColor        - The color of the rectangle object.
         //    aBlocksLights - Determines if this object should blocks lights from passing through.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         RectangleObject(const float aCoordinateX, const float aCoordinateY, const int aWidth, const int aHeight,
                         const Graphics::Color aColor, const bool aBlocksLights);
      
         //************************************************************************************************************
         //
         // Method Name: SetWidth
         //
         // Description:
         //    Updates the width of the rectangular object.
         //
         // Arguments:
         //    aWidth - The new width of the rectangular object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetWidth(const int aWidth);
      
         //************************************************************************************************************
         //
         // Method Name: GetWidth
         //
         // Description:
         //    This method returns the width of the rectangular object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the rectangular object width.
         //
         //************************************************************************************************************
         int GetWidth() const;
      
         //************************************************************************************************************
         //
         // Method Name: SetHeight
         //
         // Description:
         //    Updates the height of the rectangular object.
         //
         // Arguments:
         //    aWeight - The new height of the rectangular object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetHeight(const int aHeight);
      
         //************************************************************************************************************
         //
         // Method Name: GetHeight
         //
         // Description:
         //    This method returns the height of the rectangular object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the rectangular object height.
         //
         //************************************************************************************************************
         int GetHeight() const;
      
         //************************************************************************************************************
         //
         // Method: Draw
         //
         // Description:
         //    The drawing call to handle drawing the current rectangular object configuration on the window.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Draw() const override;

         //************************************************************************************************************
         //
         // Method: DrawForLightBlocking
         //
         // Description:
         //    The drawing call to handle drawing the current rectangular object without any color and using a passed
         //    in alpha.
         //
         // Arguments:
         //    aAlpha - The alpha for the color of the object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawForLightBlocking(unsigned int aAlpha) const override;

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
   
      public:
      
         // There are currently no public member variables for this class.
      
      protected:
      
         // There are currently no protected member variables for this class.
      
      private:
      
         // The width of the rectangular object.
         int mWidth;
      
         // The height of the rectangular object.
         int mHeight;
   
   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // RectangleObject_H