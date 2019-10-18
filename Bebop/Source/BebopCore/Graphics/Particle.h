//*********************************************************************************************************************
//
// File: Particle.h
//
// Description:
//    This class is the base class for a particle that handles the basic handling of all particle types.
//
//*********************************************************************************************************************

#ifndef Particle_H
#define Particle_H

#include "../Objects/Object.h"

namespace Bebop { namespace Graphics
{
   class Particle
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Particle
         //
         // Description:
         //    Constructor for the particle class.
         //
         // Arguments:
         //    apObject    - Pointer to the object type the particle is to be.
         //    aTimeToLive - The time left for the particle to exist.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Particle(Objects::Object* const apObject, const float aTimeToLive);

         //************************************************************************************************************
         //
         // Method Name: Update
         //
         // Description:
         //    Update to the next frame when enough time has passed.
         //
         // Arguments:
         //    aElapsedTime - The amount of time elapsed since the last update.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Update(const float aElapsedTime);

         //************************************************************************************************************
         //
         // Method: Draw
         //
         // Description:
         //    The drawing call to handle drawing the current particle configuration on the window.
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

         // The X-Coordinate position to draw the sprite on the window.
         int mPositionX;

         // The Y-Coordinate position to draw the sprite on the window.
         int mPositionY;

         Objects::Object* mpObject;

      private:

         // The time left until the particle dies.
         float mTimeToLive;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Particle_H