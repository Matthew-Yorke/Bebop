//*********************************************************************************************************************
//
// File: Event.h
//
// Description:
//    TODO: Add description.
//
//*********************************************************************************************************************

#ifndef Event_H
#define Event_H

#include <allegro5/allegro_acodec.h>
#include "../Math/Vector2D.h"

namespace Bebop { namespace Events
{
   class Event
   {
      //***************************************************************************************************************
      // Methods - Start
      //***************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Event
         //
         // Description:
         //    Constructor that sets member variables to default values.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Event();

         //************************************************************************************************************
         //
         // Method: ~Event
         //
         // Description:
         //    Destructor that frees any memory being used.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         ~Event();

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
         bool GetKeyStatus(const unsigned int aKeycode);

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
         // Method: GetTimedOut
         //
         // Description:
         //    Retreives the value of the member variable that tracks if a timeout has happened.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    True  - A timeout has happened.
         //    False - A timeout has not happened.
         //
         //************************************************************************************************************
         bool GetTimedOut();

         //************************************************************************************************************
         //
         // Method: SetTimedOut
         //
         // Description:
         //    Set the member variable that tracks if a timeout has happened or not.
         //
         // Arguments:
         //    aTimedOut - The setting of the member variable for timeout tracking.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetTimedOut(bool aTimedOut);

         //************************************************************************************************************
         //
         // Method: GetUpdateTimeDifference
         //
         // Description:
         //    Returns the time it took from the previous timeout to the lastest timeout.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the time difference from the last timeout.
         //
         //************************************************************************************************************
         float GetUpdateTimeDifference();

         //************************************************************************************************************
         //
         // Method: Execute
         //
         // Description:
         //   Makes a check of the event queue and processes all currently queued events.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Execute();

      protected:

         // There are currently no protected methods for this class.

      private:

         // Tracks if the event poller timed out, indicating an update should happen.
         bool mTimedOut;

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

         // TODO: Add member variable description.
         ALLEGRO_TIMER* mpTimer;

         // TODO: Add member variable description.
         ALLEGRO_EVENT_QUEUE* mpEventQueue;

         float mLastUpdate;

         float mUpdateTimeDifference;

         bool* mpKeys;

         bool* mpMouseButtons;

         Math::Vector2D<int> mMousePoisiton;

      //***************************************************************************************************************
      // Member Variables - End
      //***************************************************************************************************************
   };
}}

#endif // Event_H