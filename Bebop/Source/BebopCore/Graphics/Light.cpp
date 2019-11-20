//*********************************************************************************************************************
//
// File: Light.cpp
//
// Description:
//    This is the light class the create a lightsource using triangle from a point and a radius.
//
//*********************************************************************************************************************

#include "Light.h"
#include "../Math/MathConstants.h"
#include "GraphicsConstants.h"
#include "../Math/Vector2D.h"


namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Light
   //
   // Description:
   //    Constructor to set member variables to their default values and then calculate the points for the light.
   //
   // Arguments:
   //    aOriginX        - The X-Coordinate of the light origin point.
   //    aOriginY        - The Y-Coordinate of the light origin point.
   //    aRaidus         - The radius of the light source.
   //    aLightColor     - The color of the light source.
   //    aLightIntensity - Th intensity of the light itself.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Light::Light(const float aOriginX, const float aOriginY, const float aRaidus, const Color aLightColor,
                const int aLightIntensity) :
      mOriginX(aOriginX), mOriginY(aOriginY), mRaidus(aRaidus), mLightColor(aLightColor),
      mLightIntensity(aLightIntensity)
   {
      CalculateLight();
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Light::CalculateLight()
   {
      mPoints.clear();

      for (auto i = Math::DEGREES_ZERO; i < Math::DEGREES_THREE_SIXTY; i += Math::DEGREES_INCREMENT)
      {
         mPoints.push_back(std::make_pair(mOriginX + mRaidus*sin(i * Math::RADIANS_CONVERSION),
                                          mOriginY + mRaidus*cos(i * Math::RADIANS_CONVERSION)));
      }
   }

   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    Draw the light as triangles based on the points calulated.
   //
   // Arguments:
   //    aWith Color - True  = Draw the light's color.
   //                  False = Only draw the cleared area of the light. 
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::Draw(const bool aWithColor)
   {
      // Iterate through all the points calculated.
      for (auto iterator = mPoints.begin(); iterator != mPoints.end(); ++iterator)
      {
         // Check if the next item in the vector would be the end, in this case connect the points to the first point
         // in the vector.
         auto isNext = iterator + 1;
         if (isNext == mPoints.end())
         {
            auto firstPoint = mPoints.begin();
            DrawTriangle(iterator->first, iterator->second, firstPoint->first, firstPoint->second, aWithColor);
         }
         // Otherwise connect the points to the next point in the vector.
         else
         {
            auto nextPoint = iterator + 1;
            DrawTriangle(iterator->first, iterator->second, nextPoint->first, nextPoint->second, aWithColor);
         }
      }
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - Start
//*********************************************************************************************************************

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Private Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //    aWith Color   - True  = Draw the light's color.
   //                    False = Only draw the cleared area of the light.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Light::DrawTriangle(const float aFirstPointX, const float aFirstPointY, const float aSecondPointX,
                            const float aSecondPointY, const bool aWithColor)
   {
      if (true == aWithColor)
      {
         // Add the points of the triangle along with their colors at the point.
         ALLEGRO_VERTEX vertex[] =
         {
            {mOriginX, mOriginY, 0, 0, 0, al_map_rgba(mLightColor.GetRedColor(), mLightColor.GetGreenColor(),
                                                      mLightColor.GetBlueColor(), mLightColor.GetAlpha())},
            {aFirstPointX, aFirstPointY, 0, 0, 0, al_map_rgba(mLightColor.GetRedColor(), mLightColor.GetGreenColor(),
                                                              mLightColor.GetBlueColor(), NO_ALPHA)},
            {aSecondPointX, aSecondPointY, 0, 0, 0, al_map_rgba(mLightColor.GetRedColor(), mLightColor.GetGreenColor(),
                                                                mLightColor.GetBlueColor(), NO_ALPHA)},
         };
         
         // Draw the gradient triangle
         al_draw_prim(vertex, NULL, NULL, 0, 3, ALLEGRO_PRIM_TRIANGLE_STRIP);
      }
      else
      {
         // Add the points of the triangle along with their colors at the point.
         ALLEGRO_VERTEX vertex[] =
         {
            {mOriginX, mOriginY, 0, 0, 0, al_map_rgba(NO_COLOR, NO_COLOR, NO_COLOR, mLightIntensity)},
            {aFirstPointX, aFirstPointY, 0, 0, 0, LIGHTS_EDGE_COLOR},
            {aSecondPointX, aSecondPointY, 0, 0, 0, LIGHTS_EDGE_COLOR},
         };
         
         // Draw the gradient triangle
         al_draw_prim(vertex, NULL, NULL, 0, 3, ALLEGRO_PRIM_TRIANGLE_STRIP);
      }
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}