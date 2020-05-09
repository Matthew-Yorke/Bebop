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
   //    aRotation - The rotation angle in radians to the rotate the image.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Sprite::Sprite(const std::string aFilePath, const Math::Vector2D<int> aSource, const int aWidth,
                  const int aHeight, const Math::Vector2D<float> aPosition, float aRotation) :
      mSource(aSource), mWidth(aWidth), mHeight(aHeight), mPosition(aPosition), mRotation(aRotation)
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
   //    Update the sprite's window position with the passed in value.
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
   // Method: UpdateRotation
   //
   // Description:
   //    Update the sprites rotation with the passed in value.
   //    
   // Arguments:
   //    aRotation - The angle in radians to rotate the sprite.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Sprite::UpdateRotation(float aRotation)
   {
      mRotation = aRotation;
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
      // Retreive the main display drawing area so it can be reverted back to.
      ALLEGRO_BITMAP* displayDrawingArea = al_get_target_bitmap();

      // Create a temporary bitmap to retrieve the correct image from the sprite sheet.
      ALLEGRO_BITMAP* tempBitmap = al_create_bitmap(mWidth, mHeight);
      al_set_target_bitmap(tempBitmap);
      al_clear_to_color(al_map_rgb(0, 0, 0));
      al_draw_bitmap_region(mpSpriteSheet,
                            mSource.GetComponentX(),
                            mSource.GetComponentY(),
                            mWidth,
                            mHeight,
                            0.0F,
                            0.0F,
                            0);

      // Revert back to the main drawing area and draw the sprite image onto the main area.
      al_set_target_bitmap(displayDrawingArea);
      al_draw_rotated_bitmap(tempBitmap,
                             al_get_bitmap_width(tempBitmap)/2,
                             al_get_bitmap_height(tempBitmap)/2,
                             mPosition.GetComponentX() + (al_get_bitmap_width(tempBitmap)/2),
                             mPosition.GetComponentY() + (al_get_bitmap_height(tempBitmap)/2),
                             mRotation,
                             0);
      
      // Clean up memory allocation.
      al_destroy_bitmap(tempBitmap);
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
      // Retreive the main display drawing area so it can be reverted back to.
      ALLEGRO_BITMAP* displayDrawingArea = al_get_target_bitmap();

      // Create a temporary bitmap to retrieve the correct image from the sprite sheet.
      ALLEGRO_BITMAP* tempBitmap = al_create_bitmap(mWidth, mHeight);
      al_set_target_bitmap(tempBitmap);
      al_clear_to_color(al_map_rgb(0, 0, 0));
      al_draw_tinted_bitmap_region(mpSpriteSheet,
                                   al_map_rgba(0, 0, 0, aAlpha),
                                   mSource.GetComponentX(),
                                   mSource.GetComponentY(),
                                   mWidth,
                                   mHeight,
                                   0.0F,
                                   0.0F,
                                   0);

      // Revert back to the main drawing area and draw the sprite image onto the main area.
      al_set_target_bitmap(displayDrawingArea);
      al_draw_rotated_bitmap(tempBitmap,
                             al_get_bitmap_width(tempBitmap)/2,
                             al_get_bitmap_height(tempBitmap)/2,
                             mPosition.GetComponentX() + (al_get_bitmap_width(tempBitmap)/2),
                             mPosition.GetComponentY() + (al_get_bitmap_height(tempBitmap)/2),
                             mRotation,
                             0);
      
      // Clean up memory allocation.
      al_destroy_bitmap(tempBitmap);
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