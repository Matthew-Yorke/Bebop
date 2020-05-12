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
         //    apColor       - The color of the rectangle object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         RectangleObject(const Math::Vector2D<float> aCoordinates, const int aWidth, const int aHeight,
                         Graphics::Color* const apColor);
      
         //************************************************************************************************************
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
         //************************************************************************************************************
         virtual void SetCoordinateX(const float aoordianteX);
      
         //************************************************************************************************************
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
         //************************************************************************************************************
         virtual void SetCoordinateY(const float aCoordianteY);

         //************************************************************************************************************
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
         //************************************************************************************************************
         Math::Vector2D<float> GetTopLeftCorner();

         //************************************************************************************************************
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
         //************************************************************************************************************
         Math::Vector2D<float> GetTopRightCorner();

         //************************************************************************************************************
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
         //************************************************************************************************************
         Math::Vector2D<float> GetBottomLeftCorner();

         //************************************************************************************************************
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
         //************************************************************************************************************
         Math::Vector2D<float> GetBottomRightCorner();
         
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
      
         //************************************************************************************************************
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
         //************************************************************************************************************
         void UpdateCooridnates();
      
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

         // 2D vector contiaing the points of each corner of the rectangle.
         Math::Vector2D<float> mTopLeftPoint;
         Math::Vector2D<float> mTopRightPoint;
         Math::Vector2D<float> mBottomLeftPoint;
         Math::Vector2D<float> mBottomRightPoint;
   
   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // RectangleObject_H