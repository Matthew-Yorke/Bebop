//*********************************************************************************************************************
//
// File: AnimatedSprite.h
//
// Description:
//    This class handles creating and drawing of animated sprite images.
//
//*********************************************************************************************************************

#ifndef AnimatedSprite_H
#define AnimatedSprite_H

#include "Sprite.h"

namespace Bebop { namespace Graphics
{
   class AnimatedSprite : public Sprite
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method Name: AnimatedSprite
         //
         // Description:
         //  Constructor that sets default values for member variables.
         //
         // Arguments:
         //    aFilePath     - The file path where the sprite(sheet) is located.
         //    aSource       - The X-Coordinate and Y-Coordinate where the sprite image on the bitmap is located.
         //    aWidth        - The width of the sprite image.
         //    aHeight       - The height of the sprite image.
         //    aPosition     - The X-Coordinate and Y-Coordinate to draw the sprite.
         //    aFps          - The number of frames that occur in a second.
         //    aNumberFrames - The number of frames in the animation.
         //    aRotation     - The angle in radians for the rotation of the sprite.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         AnimatedSprite(const std::string aFilePath, const Math::Vector2D<int> aSource, const int aWidth,
                        const int aHeight, const Math::Vector2D<float> aPosition, const float aFps,
                        const int aNumberFrames, const float aRotation);

         //************************************************************************************************************
         //
         // Method Name: Update
         //
         // Description:
         //  Update to the next frame when enough time has passed.
         //
         // Arguments:
         //    aElapsedTime - The amount of time elapsed since the last update.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Update(const float theElapsedTime);

      protected:

         // There are currently no protected methods for this class.

      private:

         // There are currently no private methods for this class.

   //******************************************************************************************************************
   // Methods - End
   //******************************************************************************************************************
   
   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************

      public:

         // There are currently no public member variables for this class.

      protected:

         // There are currently no protected member variables for this class.

      private:

         // Holds the amount of time until a frame should be updated to the next frame.
         float mFrameTime;

         // Holds the number of frames in the current animation.
         int mNumberFrames;

         // Holds the current frame number in the number of frames.
         int mCurrentFrame;

         // Holds the amount of time that has elapsed in total for the current frame.
         float mElapsedTime;

   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // AnimatedSprite_H