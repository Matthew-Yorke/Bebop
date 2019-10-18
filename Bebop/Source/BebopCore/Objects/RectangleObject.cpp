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
   //    aCoordinateX -
   //    aCoordinateY -
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   RectangleObject::RectangleObject(const int aCoordinateX, const int aCoordinateY, const int aWidth,
                                    const int aHeight) :
      Object(aCoordinateX, aCoordinateY, (aWidth / 2), (aHeight / 2)), mWidth(aWidth), mHeight(aHeight)
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
   int RectangleObject::GetWidth()
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
   int RectangleObject::GetHeight()
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
   void RectangleObject::Draw()
   {
      al_draw_filled_rectangle(mCoordinateX, mCoordinateY, mCoordinateX + mWidth, mCoordinateY + mHeight,
                               al_map_rgba(255, 0, 255, 100));
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