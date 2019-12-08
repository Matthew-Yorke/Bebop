//*********************************************************************************************************************
//
// File: Bebop.cpp
//
// Description:
//    Class handles the initializations for the Bebop engine.
//
//*********************************************************************************************************************

#include "Bebop.h"

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
   //    Constructor for the window class that sets member variables to default values.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Bebop::Bebop()
   {
      BebopInitalized = false;
      GraphicsIntialized = false;
   }
   
   //******************************************************************************************************************
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
   //******************************************************************************************************************
   bool Bebop::InitializeBebop()
   {
      // Initialize allegro.
      if (!al_init())
      {
         return false;
      }
   
      // Primary initialization is succesful.
      BebopInitalized = true;
      return true;
   }
   
   //******************************************************************************************************************
   //
   // Method: InitializeGraphics
   //
   // Description:
   //    Intialization for the graphics portion of the engine. Intializes pieces needed for the graphics properties.
   //    Requires the primary intitalization to have already happened.
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
      // Primary intialization must come first.
      if (BebopInitalized == false)
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
   
      GraphicsIntialized = true;
      return true;
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

   // There are currently no priate methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}