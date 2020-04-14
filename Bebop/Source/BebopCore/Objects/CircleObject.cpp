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
   //    aColor        - The color of the rectangle object.
   //    aBlocksLights - Determines if this object should blocks lights from passing through.
   //
   // Return:
   //    N/A
   //
   //************************************************************************************************************
   CircleObject::CircleObject(const float aCoordinateX, const float aCoordinateY, const int aRadius,
                              const Graphics::Color aColor, const bool aBlocksLights) :
      Object(aCoordinateX, aCoordinateY, aRadius, aRadius, aColor, ObjectType::CIRCLE, aBlocksLights),
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
      al_draw_filled_circle(mCoordinateX, mCoordinateY, mRadius-1, al_map_rgba(mColor.GetRedColor(),
                                                                               mColor.GetGreenColor(),
                                                                               mColor.GetBlueColor(),
                                                                               mColor.GetAlpha()));
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
      al_draw_filled_circle(mCoordinateX, mCoordinateY, mRadius,
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