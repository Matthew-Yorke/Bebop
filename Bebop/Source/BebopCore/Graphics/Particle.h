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
#include "../Math/Motion/MotionBase.h"

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
         //    apMotion    - Pointer to the motion movement pattern.
         //    aTimeToLive - The time left for the particle to exist.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Particle(Objects::Object* const apObject, Math::MotionBase* const apMotion, const float aTimeToLive);

         //************************************************************************************************************
         //
         // Method: ~Particle
         //
         // Description:
         //    Destructor to free up any memory.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~Particle();

         //************************************************************************************************************
         //
         // Method: GetObject
         //
         // Description:
         //    Retrieve object information of the particle.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns pointer to the object information.
         //
         //************************************************************************************************************
         Objects::Object* GetObject();

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

         //************************************************************************************************************
         //
         // Method: DrawTinted
         //
         // Description:
         //    Draw a tinted version of the particle.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawTinted(unsigned int aAlpha);

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

         

      private:

         // The X-Coordinate position to draw the sprite on the window.
         int mPositionX;

         // The Y-Coordinate position to draw the sprite on the window.
         int mPositionY;

         // Pointer to the object type for the Particle
         Objects::Object* mpObject;

         // Pointer to the motion pattern being used for movement.
         Math::MotionBase* mpMotion;

         // The time left until the particle dies.
         float mTimeToLive;

         // The time this object has lived so far.
         float mLivingTime;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Particle_H