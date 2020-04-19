//*********************************************************************************************************************
//
// File: SceneLayer.h
//
// Description:
//    This class handles an individual layer within  a scene. Various objects can bee added to the scene including
//    sprites, particles, lights, and objects that will block light sources. There is a call to update the objects
//    on the layer and a call to draw the objects for the layer. The shadow map passed in the draw does now draw the
//    shadow map, but updates the passed in map with this layers lighting/shadows.
//
//*********************************************************************************************************************

#ifndef SceneLayer_H
#define SceneLayer_H

#include "Sprite.h"
#include <vector>
#include "AnimatedSprite.h"
#include "Particle.h"
#include "Light.h"
#include "../Objects/Object.h"

namespace Bebop { namespace Graphics
{
   class SceneLayer
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: SceneLayer
         //
         // Description:
         //    Constructor for the scene layer class that initalizes member variables.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         SceneLayer();

         //************************************************************************************************************
         //
         // Method: ~SceneLayer
         //
         // Description:
         //    Destructor for the scene layer class that frees any allocated memory.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~SceneLayer();

         //************************************************************************************************************
         //
         // Method: AddSprite
         //
         // Description:
         //    Adds a sprite to the scene layer.
         //
         // Arguments:
         //    apSprite - The sprite being added for this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddSprite(Sprite* apSprite);

         //************************************************************************************************************
         //
         // Method: RemoveSprite
         //
         // Description:
         //    Removes a sprite from the scene layer.
         //
         // Arguments:
         //    apSprite - The sprite being removed from this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RemoveSprite(Sprite* apSprite);

         //************************************************************************************************************
         //
         // Method: AddAnimatedSprite
         //
         // Description:
         //    Adds an animated sprite to the scene layer.
         //
         // Arguments:
         //    apAniamtedSprite - The animated being added for this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddAnimatedSprite(AnimatedSprite* apAniamtedSprite);

         //************************************************************************************************************
         //
         // Method: RemoveAnimatedSprite
         //
         // Description:
         //    Removes an animated sprite from the scene layer.
         //
         // Arguments:
         //    apAniamtedSprite - The animated being removed from this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RemoveAnimatedSprite(AnimatedSprite* apAniamtedSprite);

         //************************************************************************************************************
         //
         // Method: AddParticle
         //
         // Description:
         //    Adds a particle to the scene layer.
         //
         // Arguments:
         //    apParticle - The particle being added for this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddParticle(Particle* apParticle);

         //************************************************************************************************************
         //
         // Method: RemoveParticle
         //
         // Description:
         //    Removes a particle from the scene layer.
         //
         // Arguments:
         //    apParticle - The particle being removed from this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RemoveParticle(Particle* apParticle);

         //************************************************************************************************************
         //
         // Method: AddLight
         //
         // Description:
         //    Adds a light to the scene layer.
         //
         // Arguments:
         //    apLight - The light source being added for this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddLight(Light* apLight);

         //************************************************************************************************************
         //
         // Method: RemoveLight
         //
         // Description:
         //    Removes a light from the scene layer.
         //
         // Arguments:
         //    apLight - The light source being removed from this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RemoveLight(Light* apLight);

         //************************************************************************************************************
         //
         // Method: AddLightBlockingObjects
         //
         // Description:
         //    Adds a object that will block light sources to the scene layer.
         //
         // Arguments:
         //    apObject - The object that will block light sources being added for this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void AddLightBlockingObjects(Objects::Object* apObject);

         //************************************************************************************************************
         //
         // Method: RemoveLightBlockingObjects
         //
         // Description:
         //    Removes a object that will block light sources from the scene layer.
         //
         // Arguments:
         //    apObject - The object that will block light sources being removed from this layer.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void RemoveLightBlockingObjects(Objects::Object* apObject);

         //************************************************************************************************************
         //
         // Method: Update
         //
         // Description:
         //    Updates items within the scene layer based on the elapsed time.
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
         //    Draw objects of the scene layer onto the window.
         //
         // Arguments:
         //    apShadowLayer - Pointer to the a shadow map used to update this shadow map for lights/shadows.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Draw(ALLEGRO_BITMAP* apShadowLayer);

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
         //    apShadowLayer - Pointer to the a shadow map used to update this shadow map for lights/shadows.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void UpdateShadowLayer(ALLEGRO_BITMAP* apShadowLayer);

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

         // Vector list of the sprites within the layer.
         std::vector<Sprite*> mSprites;

         // Vector list of the animated sprites within the layer.
         std::vector<AnimatedSprite*> mAnimatedSprites;

         // Vector list of the particles within the layer.
         std::vector<Particle*> mParticles;

         // Vector list of lights within the layer.
         std::vector<Light*> mLights;

         // Vector list of objects that will block lights.
         std::vector<Objects::Object*>  mLightBlockingObjects;
   
      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // SceneLayer_H