//*********************************************************************************************************************
//
// File: Object.h
//
// Description:
//    This class handles the basic functionality of all object types as it is the parent of every object type.
//
//*********************************************************************************************************************

#ifndef Object_h
#define Object_h

#include "../Graphics/Color.h"

namespace Bebop { namespace Objects
{
   class Object
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************
   
      public:
      
         //************************************************************************************************************
         // Method Name: Object
         //
         // Description:
         //    Constructor that sets member variables to default values.
         //
         // Arguments:
         //    aCoorindateX       - The X-Coordinate to place the object upon creation.
         //    aCoorindateY       - The Y-Coordinate to place the object upon creation.
         //    aWidthCenterPoint  - The center point of the width of the object.
         //    aHeightCenterPoint - The center point of the height of the object.
         //    aColor             - The color of the rectangle object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Object(const float aCoordinateX, const float aCoordinateY, const int aWidthCenterPoint,
                const int aHeightCenterPoint, const Graphics::Color aColor);
      
         //************************************************************************************************************
         //
         // Method Name: GetCoordinateX
         //
         // Description:
         //    This method returns the current X-Coordinate of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current X-Coordinate of the object.
         //
         //************************************************************************************************************
         float GetCoordinateX() const;
      
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
         void SetCoordinateX(const float aoordianteX);
      
         //************************************************************************************************************
         //
         // Method Name: GetCoordinateY
         //
         // Description:
         //    This method returns the current Y-Coordinate of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current Y-Coordinate of the object.
         //
         //************************************************************************************************************
         float GetCoordinateY() const;
      
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
         void SetCoordinateY(const float aCoordianteY);

         //************************************************************************************************************
         //
         // Method Name: GetStartingCoordinateX
         //
         // Description:
         //    This method returns the starting X-Coordinate of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the starting X-Coordinate of the object.
         //
         //************************************************************************************************************
         float GetStartingCoordinateX() const;

         //************************************************************************************************************
         //
         // Method Name: GetStartingCoordinateY
         //
         // Description:
         //    This method returns the starting Y-Coordinate of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the starting Y-Coordinate of the object.
         //
         //************************************************************************************************************
         float GetStartingCoordinateY() const;
      
         //************************************************************************************************************
         //
         // Method Name: GetWidthCenterPoint
         //
         // Description:
         //    This method returns the current width of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current width center point of the object.
         //
         //************************************************************************************************************
         int GetWidthCenterPoint() const;
      
         //************************************************************************************************************
         //
         // Method Name: GetHeightCenterPoint
         //
         // Description:
         //    This method returns the current height center point of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current height center of the object.
         //
         //************************************************************************************************************
         int GetHeightCenterPoint() const;
      
         //************************************************************************************************************
         //
         // Method: Draw
         //
         // Description:
         //    The drawing call to handle drawing the current object configuration on the window.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         virtual void Draw() const = 0;

      protected:
      
         //************************************************************************************************************
         //
         // Method Name: SetWidthCenterPoint
         //
         // Description:
         //    This method updates the width center point of the object based on the passed in value.
         //
         // Arguments:
         //    aWidthCenterPoint - The updated width center point of the object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetWidthCenterPoint(const int aWidthCenterPoint);
      
         //************************************************************************************************************
         //
         // Method Name: SetHeightCenterPoint
         //
         // Description:
         //    This method updates the height center of the object based on the passed in value.
         //
         // Arguments:
         //    aHeightCenterPoint - The updated height center point of the object.
         //
         // Return:
         //  N/A
         //
         //************************************************************************************************************
         void SetHeightCenterPoint(const int aHeightCenterPoint);
      
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
      
         // The X-Coordinate that the object is starting at.
         float mStartingCoordinateX;

         // The Y-Coordinate that the object is starting at.
         float mStartingCoordinateY;

         // The X-Coordinate that the object is placed at based on world coordinates.
         float mCoordinateX;
      
         // The Y-Coordinate that the object is placed at based on world coordinates.
         float mCoordinateY;
      
         // The center point along the width of an object.
         int mWidthCenterPoint;
      
         // The center point along the height of an object.
         int mHeightCenterPoint;

         // The color of the object
         Graphics::Color mColor;
      
      private:
      
         // There are currently no private member variables for this class.
   
   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Object_H