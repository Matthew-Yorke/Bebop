//*********************************************************************************************************************
//
// File: SceneLayer.cpp
//
// Description:
//    This class handles an individual layer within  a scene. Various objects can bee added to the scene including
//    sprites, particles, lights, and objects that will block light sources. There is a call to update the objects
//    on the layer and a call to draw the objects for the layer. The shadow map passed in the draw does now draw the
//    shadow map, but updates the passed in map with this layers lighting/shadows.
//
//*********************************************************************************************************************

#include "SceneLayer.h"
#include "GraphicsConstants.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   SceneLayer::SceneLayer()
   {
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   SceneLayer::~SceneLayer()
   {
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::AddSprite(Sprite* apSprite)
   {
      mSprites.push_back(apSprite);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::AddAnimatedSprite(AnimatedSprite* apAniamtedSprite)
   {
      mAnimatedSprites.push_back(apAniamtedSprite);
   }
   
   //******************************************************************************************************************
   //
   // Method: AddParticle
   //
   // Description:
   //    Adds a particle  to the scene layer.
   //
   // Arguments:
   //    apParticle - The particle being added for this layer.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void SceneLayer::AddParticle(Particle* apParticle)
   {
      mParticles.push_back(apParticle);
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::AddLight(Light* apLight)
   {
      mLights.push_back(apLight);
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::AddLightBlockingObjects(Objects::Object* apObject)
   {
      mLightBlockingObjects.push_back(apObject);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::Update(const float aElapsedTime) const
   {
      for (auto iterator = mAnimatedSprites.begin(); iterator != mAnimatedSprites.end(); ++iterator)
      {
         (*iterator)->Update(aElapsedTime);
      }
      
      for (auto iterator = mParticles.begin(); iterator != mParticles.end(); ++iterator)
      {
         (*iterator)->Update(aElapsedTime);
      }

      for (auto iterator = mLights.begin(); iterator != mLights.end(); ++iterator)
      {
         (*iterator)->Update(aElapsedTime, mLightBlockingObjects);
      }
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::Draw(ALLEGRO_BITMAP* apShadowLayer)
   {
      for (auto iterator = mSprites.begin(); iterator != mSprites.end(); ++iterator)
      {
         (*iterator)->Draw();
      }

      for (auto iterator = mAnimatedSprites.begin(); iterator != mAnimatedSprites.end(); ++iterator)
      {
         (*iterator)->Draw();
      }

      for (auto iterator = mParticles.begin(); iterator != mParticles.end(); ++iterator)
      {
         (*iterator)->Draw();
      }

      DrawLightColors();

      if (apShadowLayer != nullptr)
      {
         UpdateShadowLayer(apShadowLayer);
      }
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

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::DrawLightColors() const
   {
      // Set to blend the colors together by adding the values together.
      al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

      // Draw the lights to the shadow map.
      for (auto iterator = mLights.begin(); iterator != mLights.end(); ++iterator)
      {
         (*iterator)->Draw(true);
      }

      // Set back to the default blender.
      al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void SceneLayer::UpdateShadowLayer(ALLEGRO_BITMAP* apShadowLayer)
   {
      // Retain the display bitmap information.
      ALLEGRO_BITMAP* displayBitmap = al_get_target_bitmap();

      // Set bitmap to the shadow layer and clear it.
      al_set_target_bitmap(apShadowLayer);

      // Draw areas for light blocking objects on the shadowmap.
      for (auto iterator = mLightBlockingObjects.begin(); iterator != mLightBlockingObjects.end(); ++iterator)
      {
         (*iterator)->DrawForLightBlocking(240);
      }

      // Draw blacked out area of sprites for this layer on the shadowmap.
      for (auto iterator = mSprites.begin(); iterator != mSprites.end(); ++iterator)
      {
         (*iterator)->DrawTinted(240);
      }
      for (auto iterator = mAnimatedSprites.begin(); iterator != mAnimatedSprites.end(); ++iterator)
      {
         (*iterator)->DrawTinted(240);
      }
      for (auto iterator = mParticles.begin(); iterator != mParticles.end(); ++iterator)
      {
         (*iterator)->DrawTinted(240);
      }

      // Set to blend the colors together by subtracting the light from the shadow map.
      al_set_blender(ALLEGRO_DEST_MINUS_SRC, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

      // Draw the lights to the shadow map.
      for (auto iterator = mLights.begin(); iterator != mLights.end(); ++iterator)
      {
         (*iterator)->Draw(false);
      }

      // Set back to the default blender.
      al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);

      // Set the target bitmap back to the main display and reset the blending options.
      al_set_target_bitmap(displayBitmap);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
   }
}