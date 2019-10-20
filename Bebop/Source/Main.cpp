#include <iostream>
#include "BebopCore/Graphics/Window.h"
#include "BebopCore/Graphics/Sprite.h"
#include "BebopCore/Graphics/AnimatedSprite.h"
#include "BebopCore/Graphics/Particle.h"
#include "BebopCore//Objects/CircleObject.h"
#include "BebopCore//Objects//RectangleObject.h"
#include "BebopCore/Math/SinWave.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>

using namespace Bebop::Graphics;
using namespace Bebop::Objects;
using namespace Bebop::Math;

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

   Window testWindow(400, 400);

   Sprite* testSprite = new Sprite("../TestImages/TestSprite.png", 0, 0, 32, 32, 0, 0);
   AnimatedSprite* animatedSprite = new AnimatedSprite("../TestImages/TestAnimatedSprite.png", 0, 0, 32, 32, 100, 100, 2, 2);
   Particle* rectangleParticleTest = new Particle(new RectangleObject(200, 200, 30, 50), new SinWave(1.0F, 3.0F, 0.0F), 20.0F, 5.0F);
   Particle* roundParticleTest = new Particle(new CircleObject(200, 300, 30), new SinWave(5.0F, 0.25F, 160.0F), 50.0F, 5.0F);
   
   testWindow.GetScene()->PushSprite(testSprite);
   testWindow.GetScene()->PushAnimatedSprite(animatedSprite);
   testWindow.GetScene()->PushParticle(rectangleParticleTest);
   testWindow.GetScene()->PushParticle(roundParticleTest);

   clock_t begin;
   clock_t end;
   begin = end = clock();
   double elapsedTime = 0;
   double time = 30.0;
   double moveTime = 1.0;
   while (time > 0)
   {
      // Update elapsed time.
      end = clock();
      elapsedTime = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
      begin = end;

      // Update time for this loop.
      time -= elapsedTime;

      // Move the test sprite horizontally across the screen every second.
      moveTime -= elapsedTime;
      if (moveTime < 0.0)
      {
         moveTime = 1.0;
         testSprite->UpdatePosition(testSprite->GetPositionX() + 10, testSprite->GetPositionY());
      }

      // call to update the scene.
      testWindow.GetScene()->Update(elapsedTime);

      // Draw the scene.
      testWindow.GetScene()->Draw();

      // TODO: This should be moved toa renderer class within the engine that is called to update drawings.
      al_flip_display();
      al_clear_to_color(al_map_rgb(0, 0, 0));
   }

   return 0;
}