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
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Object::Object(const int aCoordinateX, const int aCoordinateY, const int aWidthCenterPoint, 
                  const int aHeightCenterPoint) :
      mCoordinateX(aCoordinateX), mCoordinateY(aCoordinateY), mWidthCenterPoint(aWidthCenterPoint),
      mHeightCenterPoint(aHeightCenterPoint)
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
   int Object::GetCoordinateX()
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
   void Object::SetCoordinateX(const int aCoordianteX)
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
   int Object::GetCoordinateY()
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
   void Object::SetCoordinateY(const int aCoordianteY)
   {
      mCoordinateY = aCoordianteY;
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
   int Object::GetWidthCenterPoint()
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
   int Object::GetHeightCenterPoint()
   {
      return mHeightCenterPoint;
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