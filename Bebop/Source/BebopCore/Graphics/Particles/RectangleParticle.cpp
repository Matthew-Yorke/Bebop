//*********************************************************************************************************************
//
// File: RectangleParticle.cpp
//
// Description:
//    This class handles the creation and drawing of a rectangle shaped particle.
//
//*********************************************************************************************************************

#include "RectangleParticle.h"
#include <allegro5/allegro_primitives.h>

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: SquareParticle
   //
   // Description:
   //    Constructor for the rectangle shaped particle class.
   //
   // Arguments:
   //    aPositionX  - The X - Coordinate position where the particle is to be drawn.
   //    aPositionY  - The Y-Coordinate position where the particle is to be drawn.
   //    aTimeToLive - The time left for the particle to exist.
   //    aWidth      - The width  of the rectangle particle.
   //    aHeight     - The height of the rectangle shaped particle
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   RectangleParticle::RectangleParticle(const int aPositionX, const int aPositionY, const float aTimeToLive,
                                        const int aWidth, const int aHeight) :
      Particle(aPositionX, aPositionY, aTimeToLive), mWidth(aWidth), mHeight(aHeight)
   {
   }
   
   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    The drawing call to handle drawing the current rectangle shaped particle configuration on the window.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RectangleParticle::Draw()
   {
      al_draw_filled_rectangle(mPositionX, mPositionY, mPositionX + mWidth, mPositionY + mHeight,
                               al_map_rgba(255, 0, 255, 100));
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

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}