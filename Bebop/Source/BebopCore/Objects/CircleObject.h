//*********************************************************************************************************************
//
// File: CircleObject.h
//
// Description:
//    This class handles the functionality for a ciruclar object.
//
//*********************************************************************************************************************

#ifndef CircleObject_h
#define CircleObject_h

#include "Object.h"

namespace Bebop { namespace Objects
{
   class CircleObject : public Object
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************

      public:
      
         //************************************************************************************************************
         //
         // Method Name: CircleObject
         //
         // Description:
         //    Constructor that sets default values for member variables.
         //
         // Arguments:
         //    aCoordinateX - The X-Coordinate the circular object is to be displayed on the window.
         //    aCoordinateY - The Y-Coordinate the circular object is to be displayed on the window. 
         //    aRadius      - The radisu of the circular object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         CircleObject(const float aCoordinateX, const float aCoordinateY, const int aRadius);
      
         //************************************************************************************************************
         //
         // Method Name: GetRadius
         //
         // Description:
         //    This method returns the radius of the circular object.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the circular object radius.
         //
         //************************************************************************************************************
         int GetRadius();
      
         //************************************************************************************************************
         //
         // Method: Draw
         //
         // Description:
         //    The drawing call to handle drawing the current circular object configuration on the window.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void Draw() override;

      protected:
      
         // There are currently no protected methods for this class.
      
      private:
      
         // There are currently no private methods for this class.
      
   //******************************************************************************************************************
   // Methods - End
   //******************************************************************************************************************

   //******************************************************************************************************************
   // Member Variables - Start
   //******************************************************************************************************************

      public:
      
         // There are currently no public member variables for this class.
      
      protected:
      
         // There are currently no protected member variables for this class.
      
      private:
      
         // The radius of the circular object.
         int mRadius;
      
   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // CircleObject_H