//*********************************************************************************************************************
//
// File: Sprite.h
//
// Description:
//    This class handles creating and drawing of a sprite image.
//
//*********************************************************************************************************************

#ifndef Sprite_H
#define Sprite_H

#include <string>
#include <allegro5/allegro.h>

namespace Bebop { namespace Graphics
{
   class Sprite
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Sprite
         //
         // Description:
         //    Constructor for the sprite class that takes in arguments to specify the location of the image
         //    containing the sprite, the location on the image to start drawing from, and the dimensions of the
         //    sprite.
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
         //************************************************************************************************************
         Sprite(const std::string aFilePath, const int aSourceX, const int aSourceY, const int aWidth,
                const int aHeight, const int aPositionX, const int aPositionY);

         //************************************************************************************************************
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
         //************************************************************************************************************
         ~Sprite();

         //************************************************************************************************************
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
         //************************************************************************************************************
         void UpdatePosition(const int aPositionX, const int aPositionY);

         //************************************************************************************************************
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
         //************************************************************************************************************
         int GetPositionX() const;

         //************************************************************************************************************
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
         //************************************************************************************************************
         int GetPositionY() const;

         //************************************************************************************************************
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
         //************************************************************************************************************
         void Draw() const;

         //************************************************************************************************************
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
         //************************************************************************************************************
         void DrawTinted(unsigned int aAlpha) const;

      protected:

      private:

         //************************************************************************************************************
         //
         // Method: Terminate
         //
         // Description:
         //    Termination the sprite. This can be used to destroy the sprite with or without destroying the entire
         //    class object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Terminate();

      //***************************************************************************************************************
      // Methods - End
      //***************************************************************************************************************
      
      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************

      public:

         // There are currently no public member variables for this class.

      protected:

         // Holds the X-Coordinate where the sprite image resides in the sprite(sheet) bitmap.
         int mSourceX;

         // Holds the Y-Coordinate where the sprite image resides in the sprite(sheet) bitmap.
         int mSourceY;

         // Holds the width of the sprite image.
         int mWidth;

         // Holds the height of the sprite image.
         int mHeight;

         // The X-Coordinate position to draw the sprite on the window.
         int mPositionX;

         // The Y-Coordinate position to draw the sprite on the window.
         int mPositionY;

      private:

         // Holds the bitmap of the sprite(sheet) containing the image(s) of sprite.
         ALLEGRO_BITMAP* mpSpriteSheet;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Sprite_H