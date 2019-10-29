//*********************************************************************************************************************
//
// File: Vector2D.h
//
// Description:
//    This class handles functionality for a 2D vector. Direction is based ont he positive and negative values of the
//    x and y components. A positive X component is movement to the right and negative is movement to the left. A
//    positive Y component is movement downwards and negative is movement upwards.
//
//*********************************************************************************************************************

#ifndef Vector2D_H
#define Vector2D_H

namespace Bebop { namespace Math
{
   class Vector2D
   {
   //******************************************************************************************************************
   // Methods - Start
   //******************************************************************************************************************

      public:

         //************************************************************************************************************
         //
         // Method: Vector2D
         //
         // Description:
         //    
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Vector2D(const float aComponentX, const float aComponentY);

         //************************************************************************************************************
         //
         // Method: operator+
         //
         // Description:
         //    Overrides the + operator and returns the addition of this vector to another.  
         //
         // Arguments:
         //    aLeftVector  - The left side of the opertor that is being added from.
         //    aRightVector - The right side of operator that is adding to the left.
         //
         // Return:
         //    Returns the addition of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D operator+(Vector2D aLeftVector, const Vector2D aRightVector);

         //************************************************************************************************************
         //
         // Method: operator-
         //
         // Description:
         //    Overrides the - operator and returns the subtraction of this vector to another.  
         //
         // Arguments:
         //    aLeftVector  - The left side of the opertor that is being subtracted from.
         //    aRightVector - The right side of operator that is subtracting to the left.
         //
         // Return:
         //    Returns the subtraction of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D operator-(Vector2D aLeftVector, const Vector2D aRightVector);

         //************************************************************************************************************
         //
         // Method: operator*
         //
         // Description:
         //    Overrides the * operator and returns the multiplication of this vector to another.
         //
         // Arguments:
         //    aLeftVector  - The left side of the opertor that is being multiplied from.
         //    aRightVector - The right side of operator that is multiplying to the left.
         //
         // Return:
         //    Returns the multiplication of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D operator*(Vector2D aLeftVector, const Vector2D aRightVector);

         //************************************************************************************************************
         //
         // Method: operator/
         //
         // Description:
         //    Overrides the / operator and returns the division of this vector to another. 
         //
         // Arguments:
         //    aLeftVector  - The left side of the opertor that is being divided from.
         //    aRightVector - The right side of operator that is dividing to the left.
         //
         // Return:
         //    Returns the devision of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D operator/(Vector2D aLeftVector, const Vector2D aRightVector);

         //************************************************************************************************************
         //
         // Method: operator+
         //
         // Description:
         //    Overrides the += operator and returns the addition of this vector to this vector.  
         //
         // Arguments:
         //    aRightVector - The right side of operator that is adding to the this vector.
         //
         // Return:
         //    Returns the addition of this vector and the passed in vector.
         //
         //************************************************************************************************************
         Vector2D& operator+=(const Vector2D& aRightVector);

         //************************************************************************************************************
         //
         // Method: operator-
         //
         // Description:
         //    Overrides the -= operator and returns the subtraction of this vector to this vector.  
         //
         // Arguments:
         //    aRightVector - The right side of operator that is subtracting to this vector.
         //
         // Return:
         //    Returns the subtraction of this vector and the passed in vector.
         //
         //************************************************************************************************************
         Vector2D& operator-=(const Vector2D& aRightVector);

         //************************************************************************************************************
         //
         // Method: operator*
         //
         // Description:
         //    Overrides the *= operator and returns the multiplication of this vector to this vector.
         //
         // Arguments:
         //    aRightVector - The right side of operator that is multiplying to this vector.
         //
         // Return:
         //    Returns the multiplication of this vector and the passed in vector.
         //
         //************************************************************************************************************
         Vector2D& operator*=(const Vector2D& aRightVector);

         //************************************************************************************************************
         //
         // Method: operator/
         //
         // Description:
         //    Overrides the /= operator and returns the division of this vector to this vector. 
         //
         // Arguments:
         //    aRightVector - The right side of operator that is dividing to this vector.
         //
         // Return:
         //    Returns the devision of this vector and the passed in vector.
         //
         //************************************************************************************************************
         Vector2D& operator/=(const Vector2D& aRightVector);

         //************************************************************************************************************
         //
         // Method: GetComponentX
         //
         // Description:
         //    Returns the X component of the vector.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the X component of the vector.
         //
         //************************************************************************************************************
         float GetComponentX();

         //************************************************************************************************************
         //
         // Method: GetComponentY
         //
         // Description:
         //    Returns the Y component of the vector.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the Y component of the vector.
         //
         //************************************************************************************************************
         float GetComponentY();

         //************************************************************************************************************
         //
         // Method: GetMagnitude
         //
         // Description:
         //    Returns the magnitude of the vector. x^2 + y^2 = m^2.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    Returns the magnitude of the vector.
         //
         //************************************************************************************************************
         float GetMagnitude();

         //************************************************************************************************************
         //
         // Method: GetNormalized
         //
         // Description:
         //    Returns the normalized x and y values of the vector. The nromalized values of these is the assumption
         //    that magnitude is of lenght 1.0 pixel.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Vector2D GetNormalized();

      protected:

         // There are currently no protected methods for this class.

      private:

         //************************************************************************************************************
         //
         // Method: Add
         //
         // Description:
         //    Returns the vector value when this vector is added with another. 
         //
         // Arguments:
         //    aVector - The second vector that is added to this vector.
         //
         // Return:
         //    Returns the vector of the added vectors.
         //
         //************************************************************************************************************
         Vector2D& Add(const Vector2D& aVector);

         //************************************************************************************************************
         //
         // Method: Subtract
         //
         // Description:
         //    Returns the vector value when this vector is subtracted with another.   
         //
         // Arguments:
         //    aVector - The second vector that is subtracted to this vector.
         //
         // Return:
         //    Returns the vector of the subtracted vectors.
         //
         //************************************************************************************************************
         Vector2D& Subtract(const Vector2D& aVector);

         //************************************************************************************************************
         //
         // Method: Multiply
         //
         // Description:
         //    Returns the vector value when this vector is multiplied with another.
         //
         // Arguments:
         //    aVector - The second vector that is multiplied to this vector.
         //
         // Return:
         //    Returns the vector of the multiplied vectors.
         //
         //************************************************************************************************************
         Vector2D& Multiply(const Vector2D& aVector);

         //************************************************************************************************************
         //
         // Method: Divide
         //
         // Description:
         //    Returns the vector value when this vector is divided with another.
         //
         // Arguments:
         //    aVector - The second vector that is divided to this vector.
         //
         // Return:
         //    Returns the vector of the divided vectors.
         //
         //************************************************************************************************************
         Vector2D& Divide(const Vector2D& aVector);

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

         float mComponentX;

         float mComponentY;

   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };
}}

#endif // Vector2D_H