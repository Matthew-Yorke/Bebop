#include <iostream>
#include "BebopCore/Graphics/Window.h"
#include "BebopCore/Graphics/Sprite.h"
#include "BebopCore/Graphics/AnimatedSprite.h"
#include "BebopCore/Graphics/Particle.h"
#include "BebopCore/Graphics/Color.h"
#include "BebopCore//Objects/CircleObject.h"
#include "BebopCore//Objects//RectangleObject.h"
#include "BebopCore/Math/Motion/SinWaveMotion.h"
#include "BebopCore/Math/Motion/CircularMotion.h"
#include "BebopCore/Math/Vector2D.h"
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
   AnimatedSprite* animatedSprite = new AnimatedSprite("../TestImages/TestAnimatedSprite.png", 0, 0, 32, 32, 100, 100,
                                                       2, 2);
   Particle* rectangleParticleTest = new Particle(new RectangleObject(200, 200, 30, 50, Color(255, 0, 0, 255)),
                                                  new SinWaveMotion(3.0F, 0.25F, 10.0F, 0.0F), 5.0F);
   Particle* roundParticleTest = new Particle(new CircleObject(200, 300, 30, Color(0, 255, 0, 50)),
                                              new CircularMotion(100.0F, 0.5F), 5.0F);

   Vector2D a(1.0F, 2.0F);
   Vector2D b(4.0F, 4.0F);
   Vector2D addTest = a + b;
   Vector2D subtractTest = a - b;
   Vector2D multiplyTest = a * b;
   Vector2D divideTest = a / b;

   std::cout << "A.x: " << a.GetComponentX() << "     A.y: " << a.GetComponentY() << std::endl;
   std::cout << "B.x: " << b.GetComponentX() << "     B.y: " << b.GetComponentY() << std::endl;
   std::cout << "addTest.x: " << addTest.GetComponentX() << "     addTest.y: " << addTest.GetComponentY() << std::endl;
   std::cout << "subtractTest.x: " << subtractTest.GetComponentX() << "     subtractTest.y: " << subtractTest.GetComponentY() << std::endl;
   std::cout << "multiplyTest.x: " << multiplyTest.GetComponentX() << "     multiplyTest.y: " << multiplyTest.GetComponentY() << std::endl;
   std::cout << "divideTest.x: " << divideTest.GetComponentX() << "     divideTest.y: " << divideTest.GetComponentY() << std::endl;
   
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