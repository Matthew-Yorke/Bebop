//*********************************************************************************************************************
//
// File: Scene.h
//
// Description:
//    This class handles an individual scene with ability to call to update and draw the scene. Additionally, this
//    class handles calling to draw the shadow map over the scene if it exist. This class also holds the list of layers
//    within the scene and uses these layers to callf or updating and drawing of objects.
//
//*********************************************************************************************************************

#ifndef Scene_H
#define Scene_H

#include "Sprite.h"
#include <vector>
#include <map>
#include "SceneLayer.h"
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
         //************************************************************************************************************
         void AddNewLayer(int aLayerID);

         //************************************************************************************************************
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
         //************************************************************************************************************
         SceneLayer* GetLayer(int aLayerID);

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

         void ResetShadowMap() const;

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

         // Map containing the layers within a scene,
         std::map<int, SceneLayer*> mLayers;

         // The shadowmap that is overlaid ontop of the scene to simulate light and darkness of a scene.
         ALLEGRO_BITMAP* mpShadowMap;
   
      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Scene_H