//*********************************************************************************************************************
//
// File: Sprite.cpp
//
// Description:
//    This class handles an individual scene with ability to call to update and draw the scene. Additionally, this
//    class handles calling to draw the shadow map over the scene if it exist. This class also holds the list of layers
//    within the scene and uses these layers to callf or updating and drawing of objects.
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

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Scene::RemoveShadowMap()
   {
      al_destroy_bitmap(mpShadowMap);
      mpShadowMap = nullptr;
   }

   //******************************************************************************************************************
   //
   // Method: AddLayer
   //
   // Description:
   //    Add a new layer to the list of layers in the scene.
   //
   // Arguments:
   //    aLayerID - The identifier for the layer.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Scene::AddNewLayer(int aLayerID)
   {
      if (mLayers.find(aLayerID) == mLayers.end())
      {
         mLayers.insert(std::pair<int, SceneLayer*>(aLayerID, new SceneLayer()));
      }
   }

   //******************************************************************************************************************
   //
   // Method: GetLayer
   //
   // Description:
   //    TODO: Add description.
   //
   // Arguments:
   //    aLayerID - The identifier for the layer.
   //
   // Return:
   //    Returns pointer to the layer information.
   //
   //******************************************************************************************************************
   SceneLayer* Scene::GetLayer(int aLayerID)
   {
      if (mLayers.find(aLayerID) != mLayers.end())
      {
         return mLayers[aLayerID];
      }

      return nullptr;
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
      for (auto iterator = mLayers.begin(); iterator != mLayers.end(); ++iterator)
      {
         iterator->second->Update(aElapsedTime);
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
      al_clear_to_color(al_map_rgb(0, 255, 0));
      if (mpShadowMap != nullptr)
      {
         ResetShadowMap();
      }

      for (auto iterator = mLayers.begin(); iterator != mLayers.end(); ++iterator)
      {
         iterator->second->Draw(mpShadowMap);
      }

      // Draw the shadow map onto the main display.
      if (mpShadowMap != nullptr)
      {
         al_draw_bitmap(mpShadowMap, SCENE_ORIGIN, SCENE_ORIGIN, NO_DRAW_FLAGS);
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

   void Scene::ResetShadowMap() const
   {
      // Retain the display bitmap information.
      ALLEGRO_BITMAP* displayBitmap = al_get_target_bitmap();

      // Set bitmap to the shadow layer and clear it.
      al_set_target_bitmap(mpShadowMap);

      // TODO: This should be temprary 0 alpha. Eventually update to change this with a scene call.
      al_clear_to_color(al_map_rgba(NO_COLOR, NO_COLOR, NO_COLOR, 255));

      // Set the target bitmap back to the main display and reset the blending options.
      al_set_target_bitmap(displayBitmap);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
   }
}