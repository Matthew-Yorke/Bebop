//*********************************************************************************************************************
//
// File: RectangleObject.h
//
// Description:
//    This class handles the functionality for a rectangular object.    
//
//*********************************************************************************************************************

#include "RectangleObject.h"
#include <allegro5/allegro_primitives.h>

namespace Bebop { namespace Objects
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   RectangleObject::RectangleObject(const float aCoordinateX, const float aCoordinateY, const int aWidth,
                                    const int aHeight, const Graphics::Color aColor, const bool aBlocksLights) :
      Object(aCoordinateX, aCoordinateY, (aWidth / 2), (aHeight / 2), aColor, ObjectType::RECTANGLE, aBlocksLights),
      mWidth(aWidth), mHeight(aHeight)
   {
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void RectangleObject::SetWidth(const int aWidth)
   {
      mWidth = aWidth;
      SetWidthCenterPoint(mWidth / 2);
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   int RectangleObject::GetWidth() const
   {
      return mWidth;
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void RectangleObject::SetHeight(const int aHeight)
   {
      mHeight = aHeight;
      SetHeightCenterPoint(mHeight / 2);
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   int RectangleObject::GetHeight() const
   {
      return mHeight;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void RectangleObject::Draw() const
   {
      al_draw_filled_rectangle(mCoordinateX, mCoordinateY, mCoordinateX + mWidth, mCoordinateY + mHeight,
                               al_map_rgba(mColor.GetRedColor(), mColor.GetGreenColor(), mColor.GetBlueColor(),
                                           mColor.GetAlpha()));
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

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}