//*********************************************************************************************************************
//
// File: Sprite.cpp
//
// Description:
//    This class handles creating and drawing of a sprite image.
//
//*********************************************************************************************************************

#include "Sprite.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Sprite
   //
   // Description:
   //    Constructor for the sprite class that takes in arguments to specify the location of the image containing the
   //    sprite, the location on the image to start drawing from, and the dimensions of the sprite.
   //
   // Arguments:
   //    aFilePath  - This string depicts the file location of the sprite image.
   //    aSourceX   - The X-Coordinate on the image to start drawing from.
   //    aSourceY   - The Y-Coordinate on the image to start drawing from.
   //    aWidth     - The width of the sprite image.
   //    aHeight    - The height of the sprite image.
   //    aPositionX - The X-Coordinate to draw the sprite.
   //    aPositionY - The Y-Coordinate to draw the sprite.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Sprite::Sprite(const std::string aFilePath, const int aSourceX, const int aSourceY, const int aWidth,
                  const int aHeight, const int aPositionX, const int aPositionY) :
      mSourceX(aSourceX), mSourceY(aSourceY), mWidth(aWidth), mHeight(aHeight), mPositionX(aPositionX),
      mPositionY(aPositionY)
   {
      if (nullptr == (mpSpriteSheet = al_load_bitmap(aFilePath.c_str())))
      {
         Terminate();
      }
   }
   
   //******************************************************************************************************************
   //
   // Method: ~Sprite
   //
   // Description:
   //    Destructor of the sprite class that takes steps to free any allocated memory from this class.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Sprite::~Sprite()
   {
      Terminate();
   }

   //******************************************************************************************************************
   //
   // Method: UpdatePosition
   //
   // Description:
   //    Update the sprites windows position with the passed in values.
   //    
   // Arguments:
   //    aPositionX - The X-Coordinate to draw the sprite.
   //    aPositionY - The Y-Coordinate to draw the sprite.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Sprite::UpdatePosition(const int aPositionX, const int aPositionY)
   {
      mPositionX = aPositionX;
      mPositionY = aPositionY;
   }

   //******************************************************************************************************************
   //
   // Method: GetPositionX
   //
   // Description:
   //    Retrieve the current X-Coordinate position of the sprite.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the current Y-Coordinate position of the sprite.
   //
   //******************************************************************************************************************
   int Sprite::GetPositionX()
   {
      return mPositionX;
   }

   //******************************************************************************************************************
   //
   // Method: GetPositionY
   //
   // Description:
   //    Retrieve the current Y-Coordinate position of the sprite.
   //    
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the current Y-Coordinate position of the sprite.
   //
   //******************************************************************************************************************
   int Sprite::GetPositionY()
   {
      return mPositionY;
   }

   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    The drawing call to handle drawing the current sprite configuration on the window.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Sprite::Draw()
   {
      al_draw_bitmap_region(mpSpriteSheet,
                            mSourceX,
                            mSourceY,
                            mWidth,
                            mHeight,
                            mPositionX,
                            mPositionY,
                            0);
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
   // Method: Terminate
   //
   // Description:
   //    Termination the sprite. This can be used to destroy the sprite with or without destroying the entire class
   //    object.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Sprite::Terminate()
   {
      al_destroy_bitmap(mpSpriteSheet);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}