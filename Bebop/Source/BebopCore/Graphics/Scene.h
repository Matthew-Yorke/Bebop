//*********************************************************************************************************************
//
// File: Scene.h
//
// Description:
//    This class handles an individual scene with ability to call to update and draw what objects are part of the
//    scene.
//
//*********************************************************************************************************************

#ifndef Scene_H
#define Scene_H

#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Particles/Particle.h"
#include <vector>

namespace Bebop { namespace Graphics
{
   class Scene
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Scene
         //
         // Description:
         //    Constructor for the Scene class.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Scene();

         //************************************************************************************************************
         //
         // Method: PushSprite
         //
         // Description:
         //    Pushes a sprite object onto the vector list of sprites. 
         //
         // Arguments:
         //    aSprite - Pointer to the sprite object being pushed into the sprite vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushSprite(Sprite* const aSprite);

         //************************************************************************************************************
         //
         // Method: PushAnimatedSprite
         //
         // Description:
         //    Pushes a sprite object onto the vector list of animated sprites.
         //
         // Arguments:
         //    aAnimatedSprite - Pointer to the sprite object being pushed into the animated sprite vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushAnimatedSprite(AnimatedSprite* const aAnimatedSprite);

         //************************************************************************************************************
         //
         // Method: PushParticle
         //
         // Description:
         //    Pushes a particle object onto the vector list of particles.
         //
         // Arguments:
         //    aParticle - Pointer to the particle object being pushed into the particle vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushParticle(Particle* const aParticle);

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Updates items within the scene based on the elapsed time.
         //
         // Arguments:
         //    aElapsedTime - The time that has elapsed since last update.
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
         //    Draw objects of the scene onto the window.
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

         // There are currently no protected member variables for this class.

      private:

         // Vector list of the sprites within the scene.
         std::vector<Sprite*> mSprites;

         // Vector list of the animated sprites within the scene.
         std::vector<AnimatedSprite*> mAnimatedSprites;

         // Vector list of the particles within the scene.
         std::vector<Particle*> mParticles;
   
      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Scene_H