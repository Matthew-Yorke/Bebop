//*********************************************************************************************************************
//
// File: Light.h
//
// Description:
//    This is the light class the create a lightsource using triangle from a point and a radius.
//
//*********************************************************************************************************************

#ifndef Light_H
#define Light_H

#include "Color.h"
#include <vector>

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
         //    aOriginX    - The X-Coordinate of the light origin point.
         //    aOriginY    - The Y-Coordinate of the light origin point.
         //    aRaidus     - The radius of the light source.
         //    aLightColor - The color of the light source.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Light(const float aOriginX, const float aOriginY, const float aRaidus, const Color aLightColor);

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
         //    Draw the light as triangles based on the points calulated.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Draw();

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
         //
         // Method: DrawTriangle
         //
         // Description:
         //    Draw the light as triangles based on the points calulated with the very first point being the origin and
         //    passed in points the points at the edge of the triangle.
         //
         // Arguments:
         //    aFirstPointX  - X-Coordinate of the first point added to the gradient traingle.
         //    aFirstPointY  - Y-Coordinate of the first point added to the gradient traingle.
         //    aSecondPointX - X-Coordinate of the second point added to the gradient traingle.
         //    aSecondPointY - Y-Coordinate of the second point added to the gradient traingle.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawTriangle(const float aFirstPointX, const float aFirstPointY, const float aSecondPointX,
                           const float aSecondPointY);

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

         float mOriginX;
         float mOriginY;
         float mRaidus;
         Color mLightColor;

         std::vector<std::pair<float, float>> mPoints;

   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Light_H