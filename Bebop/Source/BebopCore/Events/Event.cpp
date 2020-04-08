//*********************************************************************************************************************
//
// File: Event.cpp
//
// Description:
//    TTODO: Add description.
//
//*********************************************************************************************************************

#include "Event.h"
#include <iostream>

namespace Bebop { namespace Events
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Event::Event() : mpTimer(nullptr), mTimedOut(false), mUpdateTimeDifference(0.0F)
   {
      mpKeys = new bool[ALLEGRO_KEY_MAX];
      for (auto iter = 0; iter < ALLEGRO_KEY_MAX; ++iter)
      {
         mpKeys[iter] = false;
      }

      mLastUpdate = static_cast<float>(al_current_time());

      if (!al_create_event_queue())
      {
         // TODO: log error, clean up code.
      }

      // Set FPS to 60.
      // TODO: Allow user to set FPS
      mpTimer = al_create_timer(1.0 / 60.0);

      mpEventQueue = al_create_event_queue();
      al_register_event_source(mpEventQueue, al_get_keyboard_event_source());
      al_register_event_source(mpEventQueue, al_get_timer_event_source(mpTimer));
      al_start_timer(mpTimer);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Event::~Event()
   {
      delete mpKeys;
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
   bool Event::GetKeyStatus(const unsigned int aKeycode)
   {
      // Keycode exceeds the keycode value limit indicating an incorrect checkup, therefore return false as a key that
      // does not exist cannot be pressed.
      if (aKeycode > ALLEGRO_KEY_MAX)
      {
         return false;
      }

      return mpKeys[aKeycode];
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   bool Event::GetTimedOut()
   {
      return mTimedOut;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Event::SetTimedOut(bool aTimedOut)
   {
      mTimedOut = aTimedOut;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Event::GetUpdateTimeDifference()
   {
      return mUpdateTimeDifference;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   void Event::Execute()
   {
      // Tracks what the next event will be from the event queue.
      ALLEGRO_EVENT nextEvent;

      do
      {
         // Wait an obtain the next event in the event queue.
         al_wait_for_event(mpEventQueue, &nextEvent);

         // The event was the user clicking the exit button on the display.
         if (nextEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
         {
            // TODO: Add code for this case.
         }
         // The event was the user pressing a key down.
         else if (nextEvent.type == ALLEGRO_EVENT_KEY_DOWN)
         {
            mpKeys[nextEvent.keyboard.keycode] = true;
         }
         // The event was the user releasing a downed key.
         else if (nextEvent.type == ALLEGRO_EVENT_KEY_UP)
         {
            mpKeys[nextEvent.keyboard.keycode] = false;
         }
         // The event was a timer event.
         else if (nextEvent.type == ALLEGRO_EVENT_TIMER)
         {
            // The timer event was from the FPS timer.
            // Note: This will occur ever 1/60th a second.
            if (nextEvent.timer.source == mpTimer)
            {
               //const float currentTime = static_cast<float>(al_current_time());
               //
               //mpCurrentState->Update(currentTime - lastUpdateTime);
               //
               //lastUpdateTime = currentTime;
               //redraw = true;

               // TODO: Add code for this case.
               mTimedOut = true;

               const float currentUpdate = static_cast<float>(al_current_time());
               mUpdateTimeDifference = currentUpdate - mLastUpdate;
               mLastUpdate = currentUpdate;
            }
         }
      } while (!al_is_event_queue_empty(mpEventQueue));
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

   // There are currently no private methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
   }
}