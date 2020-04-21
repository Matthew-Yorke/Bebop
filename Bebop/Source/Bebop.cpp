//*********************************************************************************************************************
//
// File: Bebop.cpp
//
// Description:
//    Class handles the initializations for the Bebop engine.
//
//*********************************************************************************************************************

#include "Bebop.h"
#include <iostream>

namespace Bebop
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Bebop
   //
   // Description:
   //    Constructor for the bebop class that sets member variables to default values.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Bebop::Bebop() : mBebopInitalized(false), mGraphicsIntialized(false), mpWindow(nullptr), mpScene(nullptr),
      mpEventHandler(nullptr)
   {
   }

   //************************************************************************************************************
   //
   // Method: ~Bebop
   //
   // Description:
   //    Destructor for the bebop class that releases any allocated memory this class manages..
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //************************************************************************************************************
   Bebop::~Bebop()
   {
      delete mpWindow;
      mpWindow = nullptr;
      delete mpScene;
      mpScene = nullptr;
   }
   
   //******************************************************************************************************************
   //
   // Method: InitializeBebop
   //
   // Description:
   //    The primary initialization of the bebop engine. Initializes required features for the engine.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    True  - Initialization was successful.
   //    False - Initialization was NOT successful.
   //
   //******************************************************************************************************************
   bool Bebop::InitializeBebop()
   {
      // Initialize allegro.
      if (!al_init())
      {
         return false;
      }

      // Primary initialization is successful.
      mBebopInitalized = true;
      return true;
   }
   
   //******************************************************************************************************************
   //
   // Method: InitializeGraphics
   //
   // Description:
   //    Initialization for the graphics portion of the engine. Initializes pieces needed for the graphics properties.
   //    Requires the primary initialization to have already happened.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    True  - Initialization was successful.
   //    False - Initialization was NOT successful.
   //
   //******************************************************************************************************************
   bool Bebop::InitializeGraphics()
   {
      // Primary initialization must come first.
      if (mBebopInitalized == false)
      {
         return false;
      }
   
      if (!al_init_image_addon())
      {
         return false;
      }
   
      if (!al_init_primitives_addon())
      {
         return false;
      }
   
      mGraphicsIntialized = true;
      return true;
   }

   //******************************************************************************************************************
   //
   // Method: InitializeEvents
   //
   // Description:
   //    Initialization for the event portion of the engine. Initializes pieces needed for the events properties.
   //    Requires the primary initialization to have already happened.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    True  - Initialization was successful.
   //    False - Initialization was NOT successful.
   //
   //******************************************************************************************************************
   bool Bebop::InitializeEvents()
   {
      // Primary initialization must come first.
      if (mBebopInitalized == false)
      {
         return false;
      }

      if (!al_install_keyboard())
      {
         return false;
      }

      if (!al_install_mouse())
      {
         return false;
      }

      if (mpEventHandler == nullptr)
      {
         mpEventHandler = new Events::Event();
      }

      return true;
   }

   //******************************************************************************************************************
   //
   // Method: CreateWindow
   //
   // Description:
   //    Create a window for the game. Requires initialization of the engine and graphics.
   //
   // Arguments:
   //    aWidth  - The width in pixels for the window.
   //    aHeight - The height in pixels for the window.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Bebop::CreateWindow(float aWidth, float aHeight)
   {
      if (mBebopInitalized == true && mGraphicsIntialized == true && mpWindow == nullptr)
      {
         mpWindow = new Graphics::Window(aWidth, aHeight);
      }
   }

   //******************************************************************************************************************
   //
   // Method: CreateScene
   //
   // Description:
   //    Create a scene for the game.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Bebop::CreateScene()
   {
      mpScene = new Graphics::Scene();
   }

   //******************************************************************************************************************
   //
   // Method: GetScene
   //
   // Description:
   //    Retrieve the scene for the game, allowing users to add additional objects into the scene.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Graphics::Scene* Bebop::GetScene()
   {
      return mpScene;
   }

   //******************************************************************************************************************
   //
   // Method: GetKeyStatus
   //
   // Description:
   //    Retreives the status of the key as either true (pressed) or false (not pressed) using the passed in keycode
   //    value for the lookup.
   //
   // Arguments:
   //    aKeycode - The keycode value of the key being checked for pressed status.
   //
   // Return:
   //    True  - The keycode value provided indicates the key is pressed.
   //    False - The keycode value provided indicates the key is not pressed.
   //
   //******************************************************************************************************************
   bool Bebop::GetKeyStatus(int aKeycode)
   {
      return mpEventHandler->GetKeyStatus(aKeycode);
   }

   //******************************************************************************************************************
   //
   // Method: GetMouseStatus
   //
   // Description:
   //    Retreives the status of the mouse button as either true (pressed) or false (not pressed) using the passed in
   //    value for the lookup.
   //
   // Arguments:
   //    aMouseButton - The value of the key being checked for pressed status.
   //
   // Return:
   //    True  - The value provided indicates the key is pressed.
   //    False - The value provided indicates the key is not pressed.
   //
   //******************************************************************************************************************
   bool Bebop::GetMouseStatus(const unsigned int aMouseButton)
   {
      return mpEventHandler->GetMouseStatus(aMouseButton);
   }

   //******************************************************************************************************************
   //
   // Method: Update
   //
   // Description:
   //    Checks any events that have happened and calls to draw the scene on a event timeout.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Bebop::Update()
   {
      static int count = 0;
      static float FPS = 0.0F;
      if (mpEventHandler != nullptr)
      {
         mpEventHandler->Execute();

         if (mpEventHandler->GetTimedOut() == true)
         {
            
            count++;
            FPS += mpEventHandler->GetUpdateTimeDifference();
            if (count == 60)
            {
               std::cout << "FPS: " << 60.0F*FPS << "\n";
               count = 0;
               FPS = 0.0F;
            }

            mpScene->Update(mpEventHandler->GetUpdateTimeDifference());
            Draw();
            mpEventHandler->SetTimedOut(false);
         }
      }
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
   // Method: Draw
   //
   // Description:
   //    Draw the scene onto the display.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Bebop::Draw()
   {
      if (mpEventHandler->GetTimedOut() == true)
      {
         al_clear_to_color(al_map_rgb(0, 0, 0));

         mpScene->Draw();

         al_flip_display();

         mpEventHandler->SetTimedOut(false);
      }
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}