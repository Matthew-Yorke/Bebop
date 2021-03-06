//*********************************************************************************************************************
//
// File: AnimatedSprite.cpp
//
// Description:
//    This class handles creating and drawing of animated sprite images.
//
//*********************************************************************************************************************

#include "AnimatedSprite.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method Name: AnimatedSprite
   //
   // Description:
   //    Constructor that sets default values for member variables.
   //
   // Arguments:
   //    aFilePath     - The file path where the sprite(sheet) is located.
   //    aSourceX      - The X-Coordinate where the sprite image on the bitmap is located.
   //    aSourceY      - The Y-Coordinate where the sprite image on the bitmap is located.
   //    aWidth        - The width of the sprite image.
   //    aHeight       - The height of the sprite image.
   //    aPositionX    - The X-Coordinate to draw the sprite.
   //    aPositionY    - The Y-Coordinate to draw the sprite.
   //    aFps          - The number of frames that occur in a second.
   //    aNumberFrames - The number of frames in the animation.
   //    aRotation     - The angle in radians for the rotation of the sprite.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   AnimatedSprite::AnimatedSprite(const std::string aFilePath, const Math::Vector2D<int> aSource, const int aWidth,
                                  const int aHeight, const Math::Vector2D<float> aPosition, const float aFps,
                                  const int aNumberFrames, const float aRotation) :
      Sprite(aFilePath, aSource, aWidth, aHeight, aPosition, aRotation),
      mFrameTime(1.0F /aFps), mNumberFrames(aNumberFrames), mCurrentFrame(0), mElapsedTime(0.0F)
   {
   }
   
   //******************************************************************************************************************
   //
   // Method Name: Update
   //
   // Description:
   //    Update to the next frame when enough time has passed.
   //
   // Arguments:
   //    aElapsedTime - The amount of time elapsed since the last update.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void AnimatedSprite::Update(const float aElapsedTime)
   {
      // Increase the elapsed time by the amount of time since the last update.
      mElapsedTime += aElapsedTime;
   
      // Check if elapsed time exceeds the frame time.
      if (mElapsedTime > mFrameTime)
      {
         // Update the next frame and reset the elapsed time.
         mCurrentFrame++;
         mElapsedTime = 0;
   
         // If the next frame is still within the bounds of the number of frames then increase the X-Coordinate of the
         // sprite(sheet) by the sprite width.
         if (mCurrentFrame < mNumberFrames)
         {
            mSource.SetComponentX(mSource.GetComponentX() + mWidth);
         }
         // The next frame is past the bounds of the number of frames. Reset the X-coordinate and current frame to the
         // first frame of the animation.
         else
         {
            mSource.SetComponentX(0);
            mCurrentFrame = 0;
         }
      }
   }

//*********************************************************************************************************************
// Public Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Protected Methods - End
//*********************************************************************************************************************

//*********************************************************************************************************************
// Private Methods - Start
//*********************************************************************************************************************

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}