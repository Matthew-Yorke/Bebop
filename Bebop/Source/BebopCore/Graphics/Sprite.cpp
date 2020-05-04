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
   //    aFilePath - This string depicts the file location of the sprite image.
   //    aSource   - The X-Coordinate nad Y-Coordinate on the image to start drawing from.
   //    aWidth    - The width of the sprite image.
   //    aHeight   - The height of the sprite image.
   //    aPosition - The X-Coordinate nad Y-Coordinate to draw the sprite.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Sprite::Sprite(const std::string aFilePath, const Math::Vector2D<int> aSource, const int aWidth,
                  const int aHeight, const Math::Vector2D<float> aPosition) :
      mSource(aSource), mWidth(aWidth), mHeight(aHeight), mPosition(aPosition)
   {
      if (nullptr == (mpSpriteSheet = al_load_bitmap(aFilePath.c_str())))
      {
         Terminate();
      }

      al_convert_mask_to_alpha(mpSpriteSheet, al_map_rgb(255, 0, 255));
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
   //    aPosition - The X-Coordinate and Y-Coordinate to draw the sprite.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Sprite::UpdatePosition(const Math::Vector2D<float> aPosition)
   {
      mPosition = aPosition;
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
   float Sprite::GetPositionX() const
   {
      return mPosition.GetComponentX();
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
   float Sprite::GetPositionY() const
   {
      return mPosition.GetComponentY();
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
   void Sprite::Draw() const
   {
      al_draw_bitmap_region(mpSpriteSheet,
                            mSource.GetComponentX(),
                            mSource.GetComponentY(),
                            mWidth,
                            mHeight,
                            mPosition.GetComponentX(),
                            mPosition.GetComponentY(),
                            0);
   }

   //******************************************************************************************************************
   //
   // Method: DrawTinted
   //
   // Description:
   //    Draw a tinted version of the sprite.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Sprite::DrawTinted(unsigned int aAlpha) const
   {
      al_draw_tinted_bitmap_region(mpSpriteSheet,
                                   al_map_rgba(0, 0, 0, aAlpha),
                                   mSource.GetComponentX(),
                                   mSource.GetComponentY(),
                                   mWidth,
                                   mHeight,
                                   mPosition.GetComponentX(),
                                   mPosition.GetComponentY(),
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