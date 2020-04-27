//*********************************************************************************************************************
//
// File: Bebop.h
//
// Description:
//    Class handles the initializations for the Bebop engine.
//
//*********************************************************************************************************************

#ifndef Bebop_H
#define Bebop_H

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "BebopCore/Graphics/Window.h"
#include "BebopCore/Graphics/Scene.h"
#include "BebopCore/Events/Event.h"

namespace Bebop
{
   class Bebop
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
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
         //************************************************************************************************************
         Bebop();

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
         ~Bebop();

         //************************************************************************************************************
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
         //************************************************************************************************************
         bool InitializeBebop();

         //************************************************************************************************************
         //
         // Method: InitializeGraphics
         //
         // Description:
         //    Initialization for the graphics portion of the engine. Initializes pieces needed for the graphics 
         //    properties. Requires the primary initialization to have already happened.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    True  - Initialization was successful.
         //    False - Initialization was NOT successful.
         //
         //************************************************************************************************************
         bool InitializeGraphics();

         //************************************************************************************************************
         //
         // Method: InitializeEvents
         //
         // Description:
         //    Initialization for the event portion of the engine. Initializes pieces needed for the events 
         //    properties. Requires the primary initialization to have already happened.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    True  - Initialization was successful.
         //    False - Initialization was NOT successful.
         //
         //************************************************************************************************************
         bool InitializeEvents();

         //************************************************************************************************************
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
         //************************************************************************************************************
         void CreateWindow(float aWidth, float aHeight);

         //************************************************************************************************************
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
         //************************************************************************************************************
         void CreateScene();

         //************************************************************************************************************
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
         //************************************************************************************************************
         Graphics::Scene* GetScene();

         //************************************************************************************************************
         //
         // Method: GetKeyStatus
         //
         // Description:
         //    Retreives the status of the key as either true (pressed) or false (not pressed) using the passed in
         //    keycode value for the lookup.
         //
         // Arguments:
         //    aKeycode - The keycode value of the key being checked for pressed status.
         //
         // Return:
         //    True  - The keycode value provided indicates the key is pressed.
         //    False - The keycode value provided indicates the key is not pressed.
         //
         //************************************************************************************************************
         bool GetKeyStatus(int aKeycode);

         //************************************************************************************************************
         //
         // Method: GetMouseStatus
         //
         // Description:
         //    Retreives the status of the mouse button as either true (pressed) or false (not pressed) using the passed
         //    in value for the lookup.
         //
         // Arguments:
         //    aMouseButton - The value of the key being checked for pressed status.
         //
         // Return:
         //    True  - The value provided indicates the key is pressed.
         //    False - The value provided indicates the key is not pressed.
         //
         //************************************************************************************************************
         bool GetMouseStatus(const unsigned int aMouseButton);

         //************************************************************************************************************
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
         //    True  - Timeout happened.
         //    False - Timeout did not happen.
         //
         //************************************************************************************************************
         bool Update();

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
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
         //************************************************************************************************************
         void Draw();

      //***************************************************************************************************************
      // Methods - End
      //***************************************************************************************************************

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************

      public:

         // There are currently no public member variables for this class.

      protected:

         // There are currently no protected member variables for this class.

      private:

         // Tracks if bebop primary initialization has happened.
         bool mBebopInitalized;

         // Tracks if the graphics initialization has happened.
         bool mGraphicsIntialized;

         // Tracks a window for the game.
         Graphics::Window* mpWindow;

         // Tracks the scene for the game.
         Graphics::Scene* mpScene;

         // Pointer to the event class to handle events such as key presses and timing of updates.
         Events::Event* mpEventHandler;

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************
   };
}

#endif // Bebop_H