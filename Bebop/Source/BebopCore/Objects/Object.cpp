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
   //    apColor            - The color of the rectangle object.
   //    aObjectType        - Determines what kind of object is created (rectangle, circle, etc.)
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Object::Object(const Math::Vector2D<float> aCoordinates, const int aWidthCenterPoint,
                  const int aHeightCenterPoint, Graphics::Color* const apColor, const ObjectType aObjectType) :
      mCoordinates(aCoordinates), mWidthCenterPoint(aWidthCenterPoint),
      mHeightCenterPoint(aHeightCenterPoint), mStartingCoordinates(aCoordinates),
      mpColor(apColor), mObjectType(aObjectType)
   {
   }

   //******************************************************************************************************************
   //
   // Method Name: ~Object
   //
   // Description:
   //    Descturctor to free any memory usage before the object is completely destroyed.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Object::~Object()
   {
      delete mpColor;
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Math::Vector2D<float> Object::GetCoordinates() const
   {
      return mCoordinates;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Object::GetCoordinateX() const
   {
      return mCoordinates.GetComponentX();
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Object::GetCoordinateY() const
   {
      return mCoordinates.GetComponentY();
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
      mCoordinates.SetComponentX(aCoordianteX);
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
      mCoordinates.SetComponentY(aCoordianteY);
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Math::Vector2D<float> Object::GetStartingCoordinates() const
   {
      return mStartingCoordinates;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Object::GetStartingCoordinateX() const
   {
      return mStartingCoordinates.GetComponentX();
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Object::GetStartingCoordinateY() const
   {
      return mStartingCoordinates.GetComponentY();
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