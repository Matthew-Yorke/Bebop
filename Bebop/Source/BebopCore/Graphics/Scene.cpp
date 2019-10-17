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

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
   }
}