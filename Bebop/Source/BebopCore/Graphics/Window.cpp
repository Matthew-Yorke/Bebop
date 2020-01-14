//*********************************************************************************************************************
//
// File: Window.cpp
//
// Description:
//    This class is used to create a display window using the Allegro 5 library.
//
//*********************************************************************************************************************

#include "Window.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Window
   //
   // Description:
   //    Constructor for the window class that takes in arguments to specify the window dimensions and then calls to
   //    initialize the creation of the window.
   //
   // Arguments:
   //    aWidth  - The width of the display window.
   //    aHeight - The height of the display window.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Window::Window(int aWidth, int aHeight) :
      mpWindow(nullptr), mWidth(aWidth), mHeight(aHeight)
   {
      mpScene = new Scene();

      if (false == Initialize())
      {
         Terminate();
      }
   }
   
   //******************************************************************************************************************
   //
   // Method: ~Window
   //
   // Description:
   //    Destructor of the window class that takes steps to free any allocated memory from this class.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Window::~Window()
   {
      Terminate();
   }
   
   //******************************************************************************************************************
   //
   // Method: GetScene
   //
   // Description:
   //    Returns the current scene to the caller.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    Returns the current scene.
   //
   //******************************************************************************************************************
   Scene* Window::GetScene() const
   {
      return mpScene;
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
   // Method: Initialize
   //
   // Description:
   //    Calls allegro functionality to create the display window with the current dimensions described by the user.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    True  - The initialization of the window was successful.
   //    False - The initialization of the window was unsuccessful.
   //
   //******************************************************************************************************************
   bool Window::Initialize()
   {
      if (!(mpWindow = al_create_display(mWidth, mHeight)))
      {
         return false;
      }
   
      return true;
   }

   //******************************************************************************************************************
   //
   // Method: Terminate
   //
   // Description:
   //    Termination the window. This can be used to destroy the window with or without destroying the entire class
   //    object.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Window::Terminate()
   {
      al_destroy_display(mpWindow);
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}