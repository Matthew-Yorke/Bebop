//*********************************************************************************************************************
//
// File: Sprite.cpp
//
// Description:
//    This class handles an individual scene with ability to call to update and draw what objects are part of the
//    scene.
//
//*********************************************************************************************************************

#include "Scene.h"
#include "GraphicsConstants.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Scene::Scene() :
      mpShadowMap(nullptr)
   {
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Scene::~Scene()
   {
      RemoveShadowMap();
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::AddShadowMap(float aWidth, float aHeight)
   {
      if (mpShadowMap == nullptr)
      {
         mpShadowMap = al_create_bitmap(aWidth, aHeight);
      }
   }

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
   void Scene::RemoveShadowMap()
   {
      al_destroy_bitmap(mpShadowMap);
      mpShadowMap = nullptr;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushSprite(Sprite* const apSprite)
   {
      mSprites.push_back(apSprite);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushAnimatedSprite(AnimatedSprite* const apAnimatedSprite)
   {
      mAnimatedSprites.push_back(apAnimatedSprite);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushParticle(Particle* const apParticle)
   {
      mParticles.push_back(apParticle);
      if (apParticle->GetObject()->GetBlocksLight() == true)
      {
         for (auto iter = mLights.begin(); iter != mLights.end(); ++iter)
         {
            (*iter)->AddObject(apParticle->GetObject());
         }
      }
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushLight(Light* const apLight)
   {
      for (auto iter = mParticles.begin(); iter != mParticles.end(); ++iter)
      {
         if ((*iter)->GetObject()->GetBlocksLight() == true)
         {
            apLight->AddObject((*iter)->GetObject());
         }
      }
      mLights.push_back(apLight);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::Update(const float aElapsedTime) const
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
         (*iterator)->Update(aElapsedTime);
      }
   }

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
   void Scene::Draw() const
   {
      // TODO: This is temporarily colored, but should be changed to black with no alpha being used.
      al_clear_to_color(al_map_rgb(0, 100, 0));

      DrawLightColors();

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

      if (mpShadowMap != nullptr)
      {
         DrawShadowMap();
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
   void Scene::DrawLightColors() const
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
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Scene::DrawShadowMap() const
   {
      // Retain the display bitmap information.
      ALLEGRO_BITMAP* displayBitmap = al_get_target_bitmap();

      // Set bitmap to the shadow layer and clear it.
      al_set_target_bitmap(mpShadowMap);
      // TODO: This should be temprary 0 alpha. Eventually update to change this with a scene call.
      al_clear_to_color(al_map_rgba(NO_COLOR, NO_COLOR, NO_COLOR, 150));

      // Set to blend the colors together by subtracting the light from the shadow map.
      al_set_separate_blender(ALLEGRO_DEST_MINUS_SRC, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA,
                              ALLEGRO_DEST_MINUS_SRC, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

      // Draw the lights to the shadow map.
      for (auto iterator = mLights.begin(); iterator != mLights.end(); ++iterator)
      {
         (*iterator)->Draw(false);
      }

      // Set back to the default blender.
      al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);

      // Set the target bitmap back to the main display and reset the blending options.
      al_set_target_bitmap(displayBitmap);

      // Draw the shadow map onto the main display.
      al_draw_bitmap(mpShadowMap, SCENE_ORIGIN, SCENE_ORIGIN, NO_DRAW_FLAGS);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
   }
}