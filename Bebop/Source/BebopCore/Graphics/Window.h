//*********************************************************************************************************************
//
// File: Window.h
//
// Description:
//    This class is sued to create  a display window using the Allegroe 5 library.
//
//*********************************************************************************************************************

#ifndef Window_H
#define Window_H

#include <allegro5/allegro_native_dialog.h>

namespace Bebop { namespace Graphics
{
   class Window
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:
   
         //************************************************************************************************************
         //
         // Method: Window
         //
         // Description:
         //    Constructor for the window class that takes in arguments to specify the window dimensions and then calls
         //    to intialize the creation of the window.
         //
         // Arguments:
         //    aWidth  - The width of the display window.
         //    aHeight - The height of the display window.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Window(int aWidth, int aHeight);
   
         //************************************************************************************************************
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
         //************************************************************************************************************
         ~Window();
   
      protected:

         // There are currently no protected methods for this class.

      private:
   
         //************************************************************************************************************
         //
         // Method: Initialize
         //
         // Description:
         //    Calls allegro functionality to create the display window with the current dimensions described by the
         //    user.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    True  - The initialization of the window was successful.
         //    False - The initializaiton of the window was unsuccessful.
         //
         //************************************************************************************************************
         bool Initialize();

         //************************************************************************************************************
         //
         // Method: Terminate
         //
         // Description:
         //    Termination the window. This can be used to destroy the window with or without destroying the entire
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

         // There are currently no public methods for this class.

      protected:

         // There are currently no prtoected methods for this class.

      private:
   
         // A pointer for the allegro display type used to crate and contain the window.
         ALLEGRO_DISPLAY* mpWindow;

         // The width of the window.
         int mWidth;
   
         // The height of the window.
         int mHeight;

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************
   };
}}

#endif // Window_H