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

      protected:

         // There are currently no protected methods for this class.

      private:

         // There are currently no private methods for this class.

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

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************
   };
}

#endif // Bebop_H