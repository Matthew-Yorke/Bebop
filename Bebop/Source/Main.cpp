#include <iostream>
#include "BebopCore/Graphics/Window.h"
#include "BebopCore/Graphics/Sprite.h"
#include "BebopCore/Graphics/AnimatedSprite.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>

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
   
   AnimatedSprite animatedSprite("../TestImages/TestAnimatedSprite.png", 0, 0, 32, 32, 2, 2);

   clock_t begin;
   clock_t end;
   begin = end = clock();
   double elapsedTime = 0;
   double time = 10.0;
   while (time > 0)
   {
      // Update elapsed time.
      end = clock();
      elapsedTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
      begin = end;

      // Update time for this loop.
      time -= elapsedTime;

      // call to update the animated sprite.
      animatedSprite.Update(elapsedTime);

      // Draw the sprites.
      animatedSprite.Draw(100, 100);
      testSprite.Draw(0, 0);

      // TODO: This should be moved toa renderer class within the engine that is called to update drawings.
      al_flip_display();
   }

   return 0;
}