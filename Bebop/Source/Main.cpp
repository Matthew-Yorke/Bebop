#include <iostream>
#include "BebopCore/Graphics/Window.h"
#include "BebopCore/Graphics/Sprite.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace Bebop::Graphics;

int main()
{
   // TODO: This needs to be added to some engine class that initializes the engine including allegro libraries.
   if (!al_init())
   {
      return false;
   }

   // TODO: This needs to be added to some engine class that initializes the engine including allegro libraries.
   if (!al_init_image_addon())
   {
      return false;
   }

   // TODO: This needs to be added to some engine class that initializes the engine including allegro libraries.
   if (!al_init_primitives_addon())
   {
      return false;
   }

   Window test(400, 400);
   Sprite testSprite("../TestImages/TestSprite.png", 0, 0, 32, 32);
   testSprite.Draw(0, 0);

   // TODO: This should be moved toa renderer class within the engine that is called to update drawings.
   al_flip_display();

   int a;
   std::cin >> a;
   return 0;
}