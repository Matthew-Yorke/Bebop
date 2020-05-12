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
#include "../Graphics/GraphicsConstants.h"

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
   //    apColor       - The color of the rectangle object.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   RectangleObject::RectangleObject(const Math::Vector2D<float> aCoordinates, const int aWidth,
                                    const int aHeight, Graphics::Color* const apColor) :
      Object(aCoordinates, (aWidth / 2), (aHeight / 2), apColor, ObjectType::RECTANGLE),
      mWidth(aWidth), mHeight(aHeight),
      mTopLeftPoint(aCoordinates),
      mTopRightPoint(GetCoordinateX() + aWidth, GetCoordinateY()),
      mBottomLeftPoint(GetCoordinateX(), GetCoordinateY() + aHeight),
      mBottomRightPoint(GetCoordinateX() + aWidth, GetCoordinateY() + aHeight)
   {
   }
   
   //******************************************************************************************************************
   //
   // Method Name: SetCoordinateX
   //
   // Description:
   //    This method updates the X-Coordinate of the object based on the passed in value.
   //
   // Arguments:
   //    aCoordianteX - The updated X-Coordinate to place the object at.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RectangleObject::SetCoordinateX(const float aCoordianteX)
   {
      Object::SetCoordinateX(aCoordianteX);
      UpdateCooridnates();
   }
   
   //******************************************************************************************************************
   //
   // Method Name: SetCoordinateY
   //
   // Description:
   //    This method updates the Y-Coordinate of the object based on the passed in value.
   //
   // Arguments:
   //    aCoordianteY - The updated Y-Coordinate to place the object at.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RectangleObject::SetCoordinateY(const float aCoordianteY)
   {
      Object::SetCoordinateY(aCoordianteY);
      UpdateCooridnates();
   }

   //******************************************************************************************************************
   //
   // Method Name: GetTopLeftCorner
   //
   // Description:
   //    Returns the vector coordinates of the top-left corner of the rectangle.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a 2D Vector coordinates for the top-left corner.
   //
   //******************************************************************************************************************
   Math::Vector2D<float> RectangleObject::GetTopLeftCorner()
   {
      return mTopLeftPoint;
   }
   
   //******************************************************************************************************************
   //
   // Method Name: GetTopRightCorner
   //
   // Description:
   //    Returns the vector coordinates of the top-right corner of the rectangle.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a 2D Vector coordinates for the top-right corner.
   //
   //******************************************************************************************************************
   Math::Vector2D<float> RectangleObject::GetTopRightCorner()
   {
      return mTopRightPoint;
   }
   
   //******************************************************************************************************************
   //
   // Method Name: GetBottomLeftCorner
   //
   // Description:
   //    Returns the vector coordinates of the bottom-left corner of the rectangle.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a 2D Vector coordinates for the bottom-left corner.
   //
   //******************************************************************************************************************
   Math::Vector2D<float> RectangleObject::GetBottomLeftCorner()
   {
      return mBottomLeftPoint;
   }
   
   //******************************************************************************************************************
   //
   // Method Name: GetBottomRightCorner
   //
   // Description:
   //    Returns the vector coordinates of the bottom-right corner of the rectangle.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns a 2D Vector coordinates for the bottom-right corner.
   //
   //******************************************************************************************************************
   Math::Vector2D<float> RectangleObject::GetBottomRightCorner()
   {
      return mBottomRightPoint;
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
      if (mpColor != nullptr)
      {
         al_draw_filled_rectangle(mCoordinates.GetComponentX(), mCoordinates.GetComponentY(),
                                  mCoordinates.GetComponentX() + mWidth, mCoordinates.GetComponentY() + mHeight,
                                  al_map_rgba(mpColor->GetRedColor(), mpColor->GetGreenColor(), mpColor->GetBlueColor(),
                                              mpColor->GetAlpha()));
      }
   }

   //******************************************************************************************************************
   //
   // Method: DrawForLightBlocking
   //
   // Description:
   //    The drawing call to handle drawing the current rectangular object without any color and using a passed in
   //    alpha.
   //
   // Arguments:
   //    aAlpha - The alpha for the color of the object.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RectangleObject::DrawForLightBlocking(unsigned int aAlpha) const
   {
      al_draw_filled_rectangle(mCoordinates.GetComponentX(), mCoordinates.GetComponentY(),
                               mCoordinates.GetComponentX() + mWidth, mCoordinates.GetComponentY() + mHeight,
                               al_map_rgba(Graphics::NO_COLOR , Graphics::NO_COLOR, Graphics::NO_COLOR, aAlpha));
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
   // Method: UpdateCooridnates
   //
   // Description:
   //    Updates the coordinates of each of the rectangle corner points.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RectangleObject::UpdateCooridnates()
   {
      // Update top-left point.
      mTopLeftPoint = mCoordinates;
      // Update top-right point.
      mTopRightPoint.SetComponentX(mCoordinates.GetComponentX() + mWidth);
      mTopRightPoint.SetComponentY(mCoordinates.GetComponentY());
      // Update bottom-left point.
      mBottomLeftPoint.SetComponentX(mCoordinates.GetComponentX());
      mBottomLeftPoint.SetComponentY(mCoordinates.GetComponentY() + mHeight);
      // Update bottom-right point.
      mBottomRightPoint.SetComponentX(mCoordinates.GetComponentX() + mWidth);
      mBottomRightPoint.SetComponentY(mCoordinates.GetComponentY() + mHeight);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}