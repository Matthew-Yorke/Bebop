//*********************************************************************************************************************
//
// File: Object.cpp
//
// Description:
//    This class handles the basic functionality of all object types as it is the parent of every object type.
//
//*********************************************************************************************************************

#include "Object.h"

namespace Bebop { namespace Objects
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Object::Object(const float aCoordinateX, const float aCoordinateY, const int aWidthCenterPoint,
                  const int aHeightCenterPoint, const Graphics::Color aColor, const ObjectType aObjectType,
                  const bool aBlocksLight) :
      mCoordinateX(aCoordinateX), mCoordinateY(aCoordinateY), mWidthCenterPoint(aWidthCenterPoint),
      mHeightCenterPoint(aHeightCenterPoint), mStartingCoordinateX(aCoordinateX), mStartingCoordinateY(aCoordinateY),
      mColor(aColor), mObjectType(aObjectType), mBlocksLight(aBlocksLight)
   {
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Object::GetCoordinateX() const
   {
      return mCoordinateX;
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
   void Object::SetCoordinateX(const float aCoordianteX)
   {
      mCoordinateX = aCoordianteX;
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Object::GetCoordinateY() const
   {
      return mCoordinateY;
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
   void Object::SetCoordinateY(const float aCoordianteY)
   {
      mCoordinateY = aCoordianteY;
   }
   
   //******************************************************************************************************************
   //
   // Method Name: GetStartingCoordinateY
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
   //******************************************************************************************************************
   float Object::GetStartingCoordinateX() const
   {
      return mStartingCoordinateX;
   }

   //******************************************************************************************************************
   //
   // Method Name: GetStartingCoordinateY
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
   //******************************************************************************************************************
   float Object::GetStartingCoordinateY() const
   {
      return mStartingCoordinateY;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   int Object::GetWidthCenterPoint() const
   {
      return mWidthCenterPoint;
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   int Object::GetHeightCenterPoint() const
   {
      return mHeightCenterPoint;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   ObjectType Object::GetObjectType() const
   {
      return mObjectType;
   }

   //******************************************************************************************************************
   //
   // Method Name: GetBlocksLight
   //
   // Description:
   //    This method returns if the object should be blocking light or not.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    True  - Should block lights.
   //    False - Should NOT block lights.
   //
   //******************************************************************************************************************
   bool Object::GetBlocksLight() const
   {
      return mBlocksLight;
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Object::SetWidthCenterPoint(const int aWidthCenterPoint)
   {
      mWidthCenterPoint = aWidthCenterPoint;
   }
   
   //******************************************************************************************************************
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
   //    N/A
   //
   //******************************************************************************************************************
   void Object::SetHeightCenterPoint(const int aHeightCenterPoint)
   {
      mHeightCenterPoint = aHeightCenterPoint;
   }

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