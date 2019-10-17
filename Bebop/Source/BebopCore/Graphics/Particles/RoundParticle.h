//*********************************************************************************************************************
//
// File: RoundParticle.h
//
// Description:
//    This class handles the creation and drawing of a round shaped particle.
//
//*********************************************************************************************************************

#ifndef RoundParticle_H
#define RoundParticle_H

#include "Particle.h"

namespace Bebop { namespace Graphics
{
   class RoundParticle : public Particle
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
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
         //************************************************************************************************************
         RoundParticle(const int aPositionX, const int aPositionY, const float aTimeToLive, const int aRaidus);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void Draw() override;

      protected:

         // There are currently no protected methods for this class.

      private:

         // There are currently no private methods for this class.

      //***************************************************************************************************************
      // Methods - End
      //***************************************************************************************************************

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************

      public:

         // There are currently no public member variables for this class.

      protected:

         // There are currently no protected member variables for this class.

      private:

         // The radius of the particle.
         int mRaidus;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // RoundParticle_H