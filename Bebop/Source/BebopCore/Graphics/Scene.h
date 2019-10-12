//*********************************************************************************************************************
//
// File: Scene.h
//
// Description:
//    
//
//*********************************************************************************************************************

#ifndef Scene_H
#define Scene_H

#include "Sprite.h"
#include "AnimatedSprite.h"
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
   
      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Scene_H