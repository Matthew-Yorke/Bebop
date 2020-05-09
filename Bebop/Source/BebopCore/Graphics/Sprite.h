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
#include "../Math/Vector2D.h"

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
         //    aSource   - The X-Coordinate nad Y-Coordinate on the image to start drawing from.
         //    aWidth    - The width of the sprite image.
         //    aHeight   - The height of the sprite image.
         //    aPosition - The X-Coordinate nad Y-Coordinate to draw the sprite.
         //    aRotation - The rotation angle in radians to the rotate the image.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Sprite(const std::string aFilePath, const Math::Vector2D<int> aSource, const int aWidth,
                const int aHeight, const Math::Vector2D<float> aPosition, float aRotation);

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
         //    Update the sprite's window position with the passed in value.
         //    
         // Arguments:
         //    aPosition - The X-Coordinate and Y-Coordinate to draw the sprite.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void UpdatePosition(const Math::Vector2D<float> aPosition);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void UpdateRotation(float aRotation);

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
         float GetPositionX() const;

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
         float GetPositionY() const;

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

         // Holds the X-Coordinate and Y-Coordinate where the sprite image resides in the sprite(sheet) bitmap.
         Math::Vector2D<int> mSource;

         // Holds the width of the sprite image.
         int mWidth;

         // Holds the height of the sprite image.
         int mHeight;

         // The X-Coordinate and Y-Coordinate to draw the sprite on the window.
         Math::Vector2D<float> mPosition;

         // The rotation of the sprite image.
         float mRotation;

      private:

         // Holds the bitmap of the sprite(sheet) containing the image(s) of sprite.
         ALLEGRO_BITMAP* mpSpriteSheet;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Sprite_H