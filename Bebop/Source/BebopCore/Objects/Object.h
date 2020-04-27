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
#include "../Math/Vector2D.h"

namespace Bebop { namespace Objects
{
   enum ObjectType
   {
      RECTANGLE,
      CIRCLE,
      NONE
   };

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
         //    aObjectType        - Determines what kind of object is created (rectangle, circle, etc.)
         //    aBlocksLights      - Determines if this object should blocks lights from passing through.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Object(const Math::Vector2D<float> aCoordinates, const int aWidthCenterPoint,
                const int aHeightCenterPoint, const Graphics::Color aColor, const ObjectType aObjectType,
                const bool aBlocksLight);
      
         //************************************************************************************************************
         //
         // Method Name: GetCoordinates
         //
         // Description:
         //    This method returns the current coordinates vector of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current coordinates of the object.
         //
         //************************************************************************************************************
         Math::Vector2D<float> GetCoordinates() const;

         //************************************************************************************************************
         //
         // Method Name: GetCoordinateX
         //
         // Description:
         //    This method returns the current x-coordinate vector of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current x-coordinate of the object.
         //
         //************************************************************************************************************
         float GetCoordinateX() const;

         //************************************************************************************************************
         //
         // Method Name: GetCoordinateY
         //
         // Description:
         //    This method returns the current y-coordinate vector of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the current y-coordinate of the object.
         //
         //************************************************************************************************************
         float GetCoordinateY() const;
      
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
         virtual void SetCoordinateX(const float aCoordianteX);
      
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
         // Method Name: GetStartingCoordinates
         //
         // Description:
         //    This method returns the starting coordinates vector of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the starting coordinates of the object.
         //
         //************************************************************************************************************
         Math::Vector2D<float> GetStartingCoordinates() const;

         //************************************************************************************************************
         //
         // Method Name: GetStartingCoordinateX
         //
         // Description:
         //    This method returns the starting x-coordinate of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the starting x-coordinates of the object.
         //
         //************************************************************************************************************
         float GetStartingCoordinateX() const;

         //************************************************************************************************************
         //
         // Method Name: GetStartingCoordinateY
         //
         // Description:
         //    This method returns the starting y-coordinate of the object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the starting y-coordinate of the object.
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
         // Method Name: GetObjectType
         //
         // Description:
         //    This method returns the object type.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the type of object.
         //
         //************************************************************************************************************
         ObjectType GetObjectType() const;

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

         //************************************************************************************************************
         //
         // Method: DrawForLightBlocking
         //
         // Description:
         //    The drawing call to handle drawing the current object without any color and using a passed in alpha.
         //
         // Arguments:
         //    aAlpha - The alpha for the color of the object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         virtual void DrawForLightBlocking(unsigned int aAlpha) const = 0;

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
      
         // The Coodrinates that the object is starting at.
         Math::Vector2D<float> mStartingCoordinates;

         // The Coordinates that the object is placed at based on world coordinates.
         Math::Vector2D<float> mCoordinates;
      
         // The center point along the width of an object.
         int mWidthCenterPoint;
      
         // The center point along the height of an object.
         int mHeightCenterPoint;

         // The color of the object.
         Graphics::Color mColor;

         // The type of object (e.g., circle, rectangle, etc.).
         ObjectType mObjectType;
      
      private:
      
         // There are currently no private member variables for this class.
   
   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Object_H