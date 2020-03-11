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
         Light(const float aOriginX, const float aOriginY, const float aRadius, const Color aLightColor,
               const int aLightIntensity);

         //************************************************************************************************************
         //
         // Method: AddObject
         //
         // Description:
         //    Add an object that can be blocked by light.
         //
         // Arguments:
         //    apObject - The object to be blocked.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddObject(Objects::Object* const apObject);

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
         void Update(const float aElapsedTime);

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
         void CalculateLight();

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
         void DrawTriangle(const float aFirstPointX, const float aFirstPointY, const float aSecondPointX,
                           const float aSecondPointY, const bool aWithColor) const;

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
         void RectangleCollisionPoint(float aCoordinateX, float aCoordinateY, Objects::Object* aThisRectangle);

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

         // The X-Coordinate of the origin of the light source.
         float mOriginX;

         // The Y-Coordinate of the origin of the light source.
         float mOriginY;

         // The radius of the light.
         float mRadius;

         // The color of the light.
         Color mLightColor;

         // The intensity of the actual light.
         int mLightIntensity;

         // Vector of X and Y coordinate for each point in the light radius.
         std::vector<std::pair<float, std::pair<float, float>>> mPoints;

         std::vector<float> mAnglesToCheck;

         // Vector of objects that can block a light source.
         std::vector<Objects::Object*> mObjects;

   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Light_H