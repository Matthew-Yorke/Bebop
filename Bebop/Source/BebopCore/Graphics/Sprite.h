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
         //    aFilePath - This string depicts the file location of the sprite image.
         //    aSourceX  - The X-Coordinate on the image to start drawing from.
         //    aSourceY  - The Y-Coordinate on the image to start drawing from.
         //    aWidth    - The width of the sprite image.
         //    aHeight   - The height of the sprite image.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Sprite(const std::string aFilePath, const int aSourceX, const int aSourceY, const int aWidth,
                const int aHeight);

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
         // Method: Draw
         //
         // Description:
         //    The drawing call to handle drawing the current sprite configuration at the desired location on the
         //    window.
         //
         // Arguments:
         //    aDestinationX - The X-Coordinate on the window where the image will be drawn on.
         //    aDestinationY - The Y-Coordinate on the window where the image will be drawn on.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Draw(const int aDestinationX, const int aDestinationY);

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

      private:

         // Holds the bitmap of the sprite(sheet) containing the image(s) of sprite.
         ALLEGRO_BITMAP* mpSpriteSheet;
   };
}}

#endif // Sprite_H