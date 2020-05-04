//*********************************************************************************************************************
//
// File: CollisionChecker.h
//
// Description:
//    This class handles checking objects for collision. This class does not handle the collision handling, but only
//    simply detection of collisions.
//
//*********************************************************************************************************************

#ifndef CollisionChecker_H
#define CollisionChecker_H

#include "../../Objects/RectangleObject.h"
#include "../../Objects/CircleObject.h"
#include <vector>

namespace Bebop { namespace Math
{
   //******************************************************************************************************************
   //
   // Method Name: RectangleRectangleCollision
   //
   // Description:
   //    Checks two rectangular objects for collision.
   //
   // Arguments:
   //    mpRectangleOne - The first rectangular object to be checked for collision.
   //    mpRectangleTwo - The second rectangular object to be checked for collision.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   bool RectangleRectangleCollision(Objects::RectangleObject* mpRectangleOne,
                                    Objects::RectangleObject* mpRectangleTwo,
                                    std::vector<Vector2D<float>>* apCollisionPoints);
   
   //******************************************************************************************************************
   //
   // Method Name: RectangleCircleCollision
   //
   // Description:
   //    Checks rectangle and circle objects for collision.
   //
   // Arguments:
   //    mpRectangle - The rectangular object to be checked for collision.
   //    mpCircle - The circular object to be checked for collision.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   bool RectangleCircleCollision(Objects::RectangleObject* mpRectangle, Objects::CircleObject* mpCircle);
   
   //******************************************************************************************************************
   //
   // Method Name: CircleCircleCollision
   //
   // Description:
   //    Checks two circle objects for collision.
   //
   // Arguments:
   //    mpCircleOne - The first circle object to be checked for collision.
   //    mpCircleTwo - The second circle object to be checked for collision.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   bool CircleCircleCollision(Objects::CircleObject* mpCircleOne, Objects::CircleObject* mpCircleTwo,
                              std::vector<Vector2D<float>>* apCollisionPoints);
   
   //******************************************************************************************************************
   //
   // Method Name: LineRectangleCollision
   //
   // Description:
   //    Checks line segment and rectangle collision.
   //
   // Arguments:
   //    aOriginPointX - The origin X-Coordinate of the line being tested.
   //    aOriginPointY - The origin Y-Coordinate of the line being tested. 
   //    aEndPointX    - The end X-Coordinate of the line being tested.
   //    aEndPointY    - The end Y-Coordinate of the line being tested.
   //    mpRectangle   - The rectangle being tested against.
   //    aCollisionX   - Pointer for the X-Coordinate of the intersection point.
   //    aCollisionY   - Pointer for the Y-Coordinate of the intersection point.
   //
   // Return:
   //    True  - There is collision between the line segment and rectangle.
   //    False - There is no collision between the line segment and rectangle.
   //
   //******************************************************************************************************************
   bool LineRectangleCollision(Vector2D<float> aOriginPoint,
                               Vector2D<float> aEndPoint,
                               Objects::RectangleObject* mpRectangle,
                               Vector2D<float>* aCollisionPoint);
   
   //******************************************************************************************************************
   //
   // Method Name: LineCircleCollision
   //
   // Description:
   //    Checks line segment and circle collision. If there is a collision, the aCollisionX and aCollisionY
   //    varaibles will be updated with the closest collision point (from the origin).
   //
   // Arguments:
   //    aOriginPointX - The origin X-Coordinate of the line being tested.
   //    aOriginPointY - The origin Y-Coordinate of the line being tested. 
   //    aEndPointX    - The end X-Coordinate of the line being tested.
   //    aEndPointY    - The end Y-Coordinate of the line being tested.
   //    apCircle      - The circle being tested against.
   //    aCollisionX   - Pointer for the X-Coordinate of the closest intersection point.
   //    aCollisionY   - Pointer for the Y-Coordinate of the closest intersection point.
   //
   // Return:
   //    True  - There is collision between the line segment and circle.
   //    False - There is no collision between the line segment and circle.
   //
   //******************************************************************************************************************
   bool LineCircleCollision(Vector2D<float> aOriginPoint,
                            Vector2D<float> aEndPoint,
                            Objects::CircleObject* apCircle,
                            Vector2D<float>* aCollisionPoint);
   
   //******************************************************************************************************************
   //
   // Method Name: LineLineCollision
   //
   // Description:
   //    Checks two line segments for collision.
   //
   // Arguments:
   //    aLineOneOriginPointX - The origin X-Coordinate of the first line being tested.
   //    aLineOneOriginPointY - The origin Y-Coordinate of the first line being tested. 
   //    aLineOneEndPointX    - The end X-Coordinate of the first line being tested.
   //    aLineOneEndPointY    - The end Y-Coordinate of the first line being tested.
   //    aLineTwoOriginPointX - The origin X-Coordinate of the second line being tested.
   //    aLineTwoOriginPointY - The origin Y-Coordinate of the second line being tested. 
   //    aLineTwoEndPointX    - The end X-Coordinate of the second line being tested.
   //    aLineTwoEndPointY    - The end Y-Coordinate of the second line being tested.
   //    aCollisionX          - Pointer for the X-Coordinate of the intersection point.
   //    aCollisionY          - Pointer for the Y-Coordinate of the intersection point.
   //
   // Return:
   //    True  - There is collision between both lines.
   //    False - There is no collision between both lines.
   //
   //******************************************************************************************************************
   bool LineLineCollision(Vector2D<float> aLineOneOriginPoint,
                          Vector2D<float> aLineOneEndPoint,
                          Vector2D<float> aLineTwoOriginPoint,
                          Vector2D<float> aLineTwoEndPoint,
                          Vector2D<float>* aCollisionPoint);

   //******************************************************************************************************************
   //
   // Method Name: PointDistances
   //
   // Description:
   //    Returns the coordinates for the collision of two lines (One and Two).
   //
   // Arguments:
   //    aOriginPointX - The origin X-Coordinate of the distance being tested.
   //    aOriginPointY - The origin Y-Coordinate of the distance being tested. 
   //    aEndPointX    - The end X-Coordinate of the distance being tested.
   //    aEndPointY    - The end Y-Coordinate of the distance being tested.
   //
   // Return:
   //    Returns the distances between two points.
   //
   //******************************************************************************************************************
   float PointDistances(Vector2D<float> aOriginPoint, Vector2D<float> aEndPoint);

   namespace
   {
      //***************************************************************************************************************
      //
      // Method Name: Orientation
      //
      // Description:
      //    Find the orientation between ordered triplet points.
      //
      // Arguments:
      //    aPointOneX   - The origin X-Coordinate of the first point.
      //    aPointOneY   - The origin Y-Coordinate of the first point.
      //    aPointTwoX   - The origin X-Coordinate of the two point.
      //    aPointTwoY   - The origin Y-Coordinate of the two point.
      //    aPointThreeX - The origin X-Coordinate of the three point.
      //    aPointThreeY - The origin Y-Coordinate of the three point.
      //
      // Return:
      //    0 = Points are collinear.
      //    1 = Points are in Clockwise orientation.
      //    2 = Points are in Counterclockwise orientation.
      //
      //***************************************************************************************************************
      int Orientation(Vector2D<float> aPointOne,
                      Vector2D<float> aPointTwo,
                      Vector2D<float> aPointThree);
      
      //***************************************************************************************************************
      //
      // Method Name: OnSegment
      //
      // Description:
      //    Given three collinear points (One, two, and Three), this function checks if point Two lies on line
      //    segment One->Three.
      //
      // Arguments:
      //    aPointOneX   - The origin X-Coordinate of the first point.
      //    aPointOneY   - The origin Y-Coordinate of the first point.
      //    aPointTwoX   - The origin X-Coordinate of the two point.
      //    aPointTwoY   - The origin Y-Coordinate of the two point.
      //    aPointThreeX - The origin X-Coordinate of the three point.
      //    aPointThreeY - The origin Y-Coordinate of the three point.
      //
      // Return:
      //    True  - Point Two lies on line segment One->Three.
      //    False - Point Two does not lie on line segment One->Three.
      //
      //***************************************************************************************************************
      bool OnSegment(Vector2D<float> aPointOne,
                     Vector2D<float> aPointTwo,
                     Vector2D<float> aPointThree);
   }
}}

#endif // CollisionChecker_H