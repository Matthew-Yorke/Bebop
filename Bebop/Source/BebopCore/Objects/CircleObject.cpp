//*********************************************************************************************************************
//
// File: CircleObject.cpp
//
// Description:
//    This class handles the functionality for a circular object.   
//
//*********************************************************************************************************************

#include "CircleObject.h"
#include <allegro5/allegro_primitives.h>
#include "../Graphics/GraphicsConstants.h"

namespace Bebop { namespace Objects
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //************************************************************************************************************
   //
   // Method Name: CircleObject
   //
   // Description:
   //    Constructor that sets default values for member variables.
   //
   // Arguments:
   //    aCoordinateX  - The X-Coordinate the circular object is to be displayed on the window.
   //    aCoordinateY  - The Y-Coordinate the circular object is to be displayed on the window. 
   //    aRadius       - The radius of the circular object.
   //    apColor       - The color of the rectangle object.
   //
   // Return:
   //    N/A
   //
   //************************************************************************************************************
   CircleObject::CircleObject(const Math::Vector2D<float> aCoordinates, const int aRadius,
                              Graphics::Color* const apColor) :
      Object(aCoordinates, aRadius, aRadius, apColor, ObjectType::CIRCLE),
      mRadius(aRadius)
   {
   }
   
   //************************************************************************************************************
   //
   // Method Name: GetRadius
   //
   // Description:
   //    This method returns the radius of the circular object.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the circular object radius.
   //
   //************************************************************************************************************
   int CircleObject::GetRadius() const
   {
      return mRadius;
   }

   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    The drawing call to handle drawing the current circular object configuration on the window.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void CircleObject::Draw() const
   {
      if (mpColor != nullptr)
      {
         al_draw_filled_circle(mCoordinates.GetComponentX(), mCoordinates.GetComponentY(),
                               mRadius-1, al_map_rgba(mpColor->GetRedColor(), mpColor->GetGreenColor(),
                                                      mpColor->GetBlueColor(), mpColor->GetAlpha()));
      }
   }

   //******************************************************************************************************************
   //
   // Method: DrawForLightBlocking
   //
   // Description:
   //    The drawing call to handle drawing the current circular object without any color and using a passed in alpha.
   //
   // Arguments:
   //    aAlpha - The alpha for the color of the object.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void CircleObject::DrawForLightBlocking(unsigned int aAlpha) const
   {
      al_draw_filled_circle(mCoordinates.GetComponentX(), mCoordinates.GetComponentY(), mRadius,
                            al_map_rgba(Graphics::NO_COLOR, Graphics::NO_COLOR, Graphics::NO_COLOR, aAlpha));
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

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}