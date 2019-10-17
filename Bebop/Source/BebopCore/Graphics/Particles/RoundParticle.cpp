//*********************************************************************************************************************
//
// File: SquareParticle.cpp
//
// Description:
//    This class handles the creation and drawing of a round shaped particle.
//
//*********************************************************************************************************************

#include "RoundParticle.h"
#include <allegro5/allegro_primitives.h>

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: RoundParticle
   //
   // Description:
   //    Constructor for the round shaped particle class.
   //
   // Arguments:
   //    aPositionX  - The X - Coordinate position where the particle is to be drawn.
   //    aPositionY  - The Y-Coordinate position where the particle is to be drawn.
   //    aTimeToLive - The time left for the particle to exist.
   //    aRaidus     - The radius of the ciruclar particle.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   RoundParticle::RoundParticle(const int aPositionX, const int aPositionY, const float aTimeToLive,
                                const int aRadius) :
      Particle(aPositionX, aPositionY, aTimeToLive), mRaidus(aRadius)
   {
   }
   
   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    The drawing call to handle drawing the current round shaped particle configuration on the window.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void RoundParticle::Draw()
   {
      al_draw_filled_circle(mPositionX, mPositionY, mRaidus, al_map_rgba(255, 0, 255, 100));
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