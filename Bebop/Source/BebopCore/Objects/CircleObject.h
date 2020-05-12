//*********************************************************************************************************************
//
// File: CircleObject.h
//
// Description:
//    This class handles the functionality for a circular object.
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
         //    aCoordinateX  - The X-Coordinate the circular object is to be displayed on the window.
         //    aCoordinateY  - The Y-Coordinate the circular object is to be displayed on the window. 
         //    aRadius       - The radius of the circular object.
         //    apColor       - The color of the rectangle object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         CircleObject(const Math::Vector2D<float> aCoordinates, const int aRadius,
                      Graphics::Color* const apColor);
      
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
         int GetRadius() const;
      
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
         void Draw() const override;

         //************************************************************************************************************
         //
         // Method: DrawForLightBlocking
         //
         // Description:
         //    The drawing call to handle drawing the current circular object without any color and using a passed in
         //    alpha.
         //
         // Arguments:
         //    aAlpha - The alpha for the color of the object.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void DrawForLightBlocking(unsigned int aAlpha) const override;

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