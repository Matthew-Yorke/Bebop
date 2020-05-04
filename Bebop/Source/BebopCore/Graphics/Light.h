//*********************************************************************************************************************
//
// File: Light.h
//
// Description:
//    This is the light class the create a light source using triangle from a point and a radius.
//
//*********************************************************************************************************************

#ifndef Light_H
#define Light_H

#include "Color.h"
#include "../Objects/Object.h"
#include <vector>
#include "../Objects//RectangleObject.h"
#include "../Objects//CircleObject.h"
#include "../Math/Vector2D.h"

namespace Bebop { namespace Graphics
{
   class Light
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Light
         //
         // Description:
         //    Constructor to set member variables to their default values and then calculate the points for the light.
         //
         // Arguments:
         //    aOriginX        - The X-Coordinate of the light origin point.
         //    aOriginY        - The Y-Coordinate of the light origin point.
         //    aRadius         - The radius of the light source.
         //    aLightColor     - The color of the light source.
         //    aLightIntensity - Th intensity of the light itself.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Light(Math::Vector2D<float> aOrigin, const float aRadius, const Color aLightColor,
               const int aLightIntensity);

         //************************************************************************************************************
         //
         // Method: GetCoordinateX
         //
         // Description:
         //    UReturn the origin X-Coordinate of the light source.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the float value that is the X-Coordinate of the light source origin.
         //
         //************************************************************************************************************
         float GetCoordinateX();
         
         //************************************************************************************************************
         //
         // Method: SetCoordinateX
         //
         // Description:
         //    Update the X-Coordinate origin point for the light source.
         //
         // Arguments:
         //    aCoordinateX - The float value to update the X-Cooridnate origin point of the light source.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetCoordinateX(float aCoordinateX);
         
         //************************************************************************************************************
         //
         // Method: GetCoordinateY
         //
         // Description:
         //    UReturn the origin Y-Coordinate of the light source.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the float value that is the Y-Coordinate of the light source origin.
         //
         //************************************************************************************************************
         float GetCoordinateY();
         
         //************************************************************************************************************
         //
         // Method: SetCoordinateY
         //
         // Description:
         //    Update the Y-Coordinate origin point for the light source.
         //
         // Arguments:
         //    aCoordinateY - The float value to update the Y-Cooridnate origin point of the light source.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetCoordinateY(float aCoordinateY);

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Update the light calculations.
         //
         // Arguments:
         //    aElapsedTime - The amount of time since the last update.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Update(const float aElapsedTime, std::vector<Objects::Object*> aBlockingObjects);

         //************************************************************************************************************
         //
         // Method: CalculateLight
         //
         // Description:
         //    Calculate the point for the light within the range of 360 degrees.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void CalculateLight(std::vector<Objects::Object*> aBlockingObjects);

         //************************************************************************************************************
         //
         // Method: Draw
         //
         // Description:
         //    Draw the light as triangles based on the points calculated.
         //
         // Arguments:
         //    aWith Color - True  = Draw the light's color.
         //                  False = Only draw the cleared area of the light. 
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Draw(const bool aWithColor) const;

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
         //
         // Method: DrawTriangle
         //
         // Description:
         //    Draw the light as triangles based on the points calculated with the very first point being the origin
         //    and passed in points the points at the edge of the triangle.
         //
         // Arguments:
         //    aFirstPointX  - X-Coordinate of the first point added to the gradient triangle.
         //    aFirstPointY  - Y-Coordinate of the first point added to the gradient triangle.
         //    aSecondPointX - X-Coordinate of the second point added to the gradient triangle.
         //    aSecondPointY - Y-Coordinate of the second point added to the gradient triangle.
         //    aWith Color   - True  = Draw the light's color.
         //                    False = Only draw the cleared area of the light.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawTriangle(Math::Vector2D<float> aFirstPoint, Math::Vector2D<float> aSecondPoint, const bool aWithColor) const;

         //************************************************************************************************************
         //
         // Method: RectangleCollisionPoint
         //
         // Description:
         //    Checks light collision against a point on a rectangle.
         //
         // Arguments:
         //    aCoordinateX   - X-Coordinate of the point on the rectangle being checked..
         //    aCoordinateY   - Y-Coordinate of the point on the rectangle being checked..
         //    aThisRectangle - Pointer to the rectangle being checked..
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RectangleCollisionPoint(Math::Vector2D<float> aRectangleCoordinate, Objects::Object* aThisRectangle);

         //******************************************************************************************************************
         //
         // Method: CircleCollisionPoints
         //
         // Description:
         //    Gets light blocking points along a circle.
         //
         // Arguments:
         //    aThisCircle - Pointer to the rectangle being checked.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void CircleCollisionPoints(Objects::CircleObject* aThisCircle,
                                    std::vector<Math::Vector2D<float>>* apCollisionPoints);

         //************************************************************************************************************
         //
         // Method: CheckObjectCollisions
         //
         // Description:
         //    Checks if the ray from the light origin to the end point will pass through any other objects. Returns a
         //    bool based on the results.
         //
         // Arguments:
         //    aEndPointX - The X-Coordinate of the end point being checked against the light origin.
         //    aEndPointY - The Y-Coordinate of the end point being checked against the light origin.
         //    testingObject - The object being tested, used to not test itself.
         //
         // Return:
         //    True  - The ray passes through some other object.
         //    False - The ray doesn't pass through any other objects.
         //
         //************************************************************************************************************
         bool CheckObjectCollisions(Math::Vector2D<float> aEndPoint, Objects::Object* testingObject);

         //************************************************************************************************************
         //
         // Method: RectangleRectangleCollisionPoints
         //
         // Description:
         //    Checks for collision points between two rectangles based on the origin of the light. For example, if the
         //    light is above both rectangles and to the right of the first rectangle then the only two lines needed
         //    to be check for collision is the top horizontal edge of the first rectangle agaisnt the right vertical
         //    edge of the second rectangle as that is the only collision point the light will possiblu reach without
         //    passingthrough either rectangle.
         //
         // Arguments:
         //    apRectangleOne - One of the rectangle to check for collision points.
         //    apRectangleTwo - The second rectangle to check for collision points.
         //    apCollisionPoints - The collection of possible collision points known to the light source.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RectangleRectangleCollisionPoints(Objects::RectangleObject* apRectangleOne,
                                                Objects::RectangleObject* apRectangleTwo,
                                                std::vector<Math::Vector2D<float>>* apCollisionPoints);

         //************************************************************************************************************
         //
         // Method: LightRectangleCollisionPoints
         //
         // Description:
         //    Gather points where the outer edge of the light source collides with sides of a rectangle. The only
         //    sides to be checked are closest to the light source itself (e.g., if the light is above and to the left
         //    of the rectangle, only the top and left edge need to be checked for collision points).
         //
         // Arguments:
         //    apRectangle       - Rectangle to check for collision points against the light.
         //    apCollisionPoints - The collection of possible collision points known to the light source.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void LightRectangleCollisionPoints(Objects::RectangleObject* apRectangle,
                                            std::vector<Math::Vector2D<float>>* apCollisionPoints);

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

         // The coordinates of the origin of the light source.
         Math::Vector2D<float> mOrigin;

         // The radius of the light.
         float mRadius;

         // The color of the light.
         Color mLightColor;

         // The intensity of the actual light.
         int mLightIntensity;

         // Vector of X and Y coordinate for each point in the light radius.
         // Vector Composition: <Angle <X-Coordiante, Y-Coordinate>>
         std::vector<std::pair<float, Math::Vector2D<float>>> mPoints;

         // Vectors of angles to check for the light sweeping checks. This sweeping check is to check each angle
         // to determine points where the light will reach at these angles. The second part of the pair determines
         // if the check should skip redundancy object collision (true) or not (false).
         std::vector<std::pair<float,bool>> mAnglesToCheck;

         // Vector of objects that can block a light source.
         std::vector<Objects::Object*> mObjects;

         // TODO: This needs a better location.
         struct Line
         {
            float originX;
            float originY;
            float endX;
            float endY;
         };

   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Light_H