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
#include <vector>
#include "AnimatedSprite.h"
#include "Particle.h"
#include "Light.h"


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
         // Method: PushLight
         //
         // Description:
         //    Pushes a light object onto the vector list of lights.
         //
         // Arguments:
         //    aLight - Pointer to the light object being pushed into the light vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushLight(Light* const aLight);

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
         void Update(const float aElapsedTime) const;

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
         void Draw() const;

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
         //
         // Method: DrawLightColors
         //
         // Description:
         //    Draw light's color onto the main display.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawLightColors() const;

         //************************************************************************************************************
         //
         // Method: DrawShadowMap
         //
         // Description:
         //    Draw shadow map for the lights onto the main display, this does not include the light's color.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawShadowMap() const;

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

         std::vector<Light*> mLights;

         ALLEGRO_BITMAP* mpShadowMap;
   
      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Scene_H