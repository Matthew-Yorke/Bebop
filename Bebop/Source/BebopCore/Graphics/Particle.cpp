//*********************************************************************************************************************
//
// File: Particle.cpp
//
// Description:
//    This class handles creating and drawing of a sprite image.
//
//*********************************************************************************************************************

#include "Particle.h"

namespace Bebop { namespace Graphics
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Particle
   //
   // Description:
   //    Constructor for the particle class.
   //
   // Arguments:
   //    apObject    - Pointer to the object type the particle is to be.
   //    apMotion    - Pointer to the motion movement pattern.
   //    aTimeToLive - The time left for the particle to exist.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Particle::Particle(Objects::Object* const apObject, Math::MotionBase* const apMotion, const float aTimeToLive) :
      mpObject(apObject), mpMotion(apMotion), mTimeToLive(aTimeToLive), mLivingTime(0.0F)
   {
   }

   //******************************************************************************************************************
   //
   // Method: ~Particle
   //
   // Description:
   //    Destructor to free up any memory.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Particle::~Particle()
   {
      delete mpObject;
      delete mpMotion;
   }

   //******************************************************************************************************************
   //
   // Method: Update
   //
   // Description:
   //    Reduce the time to live by the amount of elapsed time passed in.
   //
   // Arguments:
   //    aElapsedTime - The amount of time that has elapsed for this update.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Particle::Update(const float aElapsedTime)
   {
      mLivingTime += aElapsedTime;

      mpObject->SetCoordinateX(mpObject->GetStartingCoordinateX() + mpMotion->GetPositionX(mLivingTime));
      mpObject->SetCoordinateY(mpObject->GetStartingCoordinateY() + mpMotion->GetPositionY(mLivingTime));
   }

   //******************************************************************************************************************
   //
   // Method: Draw
   //
   // Description:
   //    The drawing call to handle drawing the current particle configuration on the window.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   void Particle::Draw()
   {
      mpObject->Draw();
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

   // There are currently no protected methods for this class.

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}