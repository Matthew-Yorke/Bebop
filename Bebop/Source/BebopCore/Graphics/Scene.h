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
         // Method: ~Scene
         //
         // Description:
         //    Deconstructor for the Scene class that frees any allocated memory this class manages.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~Scene();

         //************************************************************************************************************
         //
         // Method: AddShadowMap
         //
         // Description:
         //    Add a shadow map into the scene if it doesn't already exist.
         //
         // Arguments:
         //    aWidth  - The width of the shadow map. This typically should be the width of the window.
         //    aHeight - The height of the shadow map. This typically should be the height of the window.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddShadowMap(float aWidth, float aHeight);

         //************************************************************************************************************
         //
         // Method: RemoveShadowMap
         //
         // Description:
         //    Remove the shadow map from the scene.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RemoveShadowMap();

         //************************************************************************************************************
         //
         // Method: PushSprite
         //
         // Description:
         //    Pushes a sprite object onto the vector list of sprites. 
         //
         // Arguments:
         //    apSprite - Pointer to the sprite object being pushed into the sprite vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushSprite(Sprite* const apSprite);

         //************************************************************************************************************
         //
         // Method: PushAnimatedSprite
         //
         // Description:
         //    Pushes a sprite object onto the vector list of animated sprites.
         //
         // Arguments:
         //    apAnimatedSprite - Pointer to the sprite object being pushed into the animated sprite vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushAnimatedSprite(AnimatedSprite* const apAnimatedSprite);

         //************************************************************************************************************
         //
         // Method: PushParticle
         //
         // Description:
         //    Pushes a particle object onto the vector list of particles.
         //
         // Arguments:
         //    apParticle - Pointer to the particle object being pushed into the particle vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushParticle(Particle* const apParticle);

         //************************************************************************************************************
         //
         // Method: PushLight
         //
         // Description:
         //    Pushes a light object onto the vector list of lights.
         //
         // Arguments:
         //    apLight - Pointer to the light object being pushed into the light vector.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void PushLight(Light* const apLight);

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

         // Vector list of lights within the scene.
         std::vector<Light*> mLights;

         // The shadowmap that is overlaid ontop of the scene to simulate lgith and darkness of a scene.
         ALLEGRO_BITMAP* mpShadowMap;
   
      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Scene_H