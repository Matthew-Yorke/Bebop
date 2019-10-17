//*********************************************************************************************************************
//
// File: RectangleParticle.h
//
// Description:
//    This class handles the creation and drawing of a rectangle shaped particle.
//
//*********************************************************************************************************************

#ifndef RectangleParticle_H
#define RectangleParticle_H

#include "Particle.h"

namespace Bebop { namespace Graphics
{
   class RectangleParticle : public Particle
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: RectangleParticle
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
         //************************************************************************************************************
         RectangleParticle(const int aPositionX, const int aPositionY, const float aTimeToLive,
                           const int aWidth, const int aHeight);

         //************************************************************************************************************
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

         // The width of the rectangle particle.
         int mWidth;

         // The height of the rectangle particle.
         int mHeight;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // RectangleParticle_H