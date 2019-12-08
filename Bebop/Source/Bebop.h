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
         //    Constructor for the window class that sets member variables to default values.
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
         // Method: InitializeBebop
         //
         // Description:
         //    The primary initialization of the bebop engine. Intializes required features for the engine.
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
         //    Intialization for the graphics portion of the engine. Intializes pieces needed for the graphics 
         //    properties. Requires the primary intitalization to have already happened.
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

         // Tracks if bebop primary intialization has happened.
         bool BebopInitalized;

         // Tracks if the graphics intialization has happened.
         bool GraphicsIntialized;

      //***************************************************************************************************************
      // Member Variables - Start
      //***************************************************************************************************************
   };
}

#endif // Bebop_H