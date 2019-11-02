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
   Scene::Scene()
   {
      // TODO: This constructor needs to pass in a scene width and height, the 400, 400 is temporary for the shadow map
      //       for testing purposes.
      mpShadowMap = al_create_bitmap(400, 400);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushSprite(Sprite* const aSprite)
   {
      mSprites.push_back(aSprite);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushAnimatedSprite(AnimatedSprite* const aAnimatedSprite)
   {
      mAnimatedSprites.push_back(aAnimatedSprite);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushParticle(Particle* const aParticle)
   {
      mParticles.push_back(aParticle);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::PushLight(Light* const aLight)
   {
      mLights.push_back(aLight);
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
   void Scene::Update(const float aElapsedTime)
   {
      for (auto iterator = mAnimatedSprites.begin(); iterator != mAnimatedSprites.end(); ++iterator)
      {
         (*iterator)->Update(aElapsedTime);
      }

      for (auto iterator = mParticles.begin(); iterator != mParticles.end(); ++iterator)
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
   void Scene::Draw()
   {
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

      DrawShadowMap();
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
   void Scene::DrawLightColors()
   {
      // Set to blend the colors together by adding the values together.
      al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

      // Draw the the ligths to the shadow map.
      for (auto iterator = mLights.begin(); iterator != mLights.end(); ++iterator)
      {
         (*iterator)->Draw(true);
      }
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
   void Scene::DrawShadowMap()
   {
      // Retain the display bitmap information.
      ALLEGRO_BITMAP* displayBitmap = al_get_target_bitmap();

      // Set bitmap to the shdow layer and clear it.
      al_set_target_bitmap(mpShadowMap);
      al_clear_to_color(al_map_rgb(NO_COLOR, NO_COLOR, NO_COLOR));

      // Set to blend the colors together byt subtracting the light from the shadow map.
      al_set_blender(ALLEGRO_DEST_MINUS_SRC, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

      // Draw the the ligths to the shadow map.
      for (auto iterator = mLights.begin(); iterator != mLights.end(); ++iterator)
      {
         (*iterator)->Draw(false);
      }

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