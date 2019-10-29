//*********************************************************************************************************************
//
// File: Vector2D.cpp
//
// Description:
//    This class handles functionality for a 2D vector. Direction is based ont he positive and negative values of the
//    x and y components. A positive X component is movement to the right and negative is movement to the left. A
//    positive Y component is movement downwards and negative is movement upwards.
//
//*********************************************************************************************************************

#include "Vector2D.h"
#include "MathConstants.h"

namespace Bebop { namespace Math
{
//*********************************************************************************************************************
// Public Methods - Start
//*********************************************************************************************************************

   //******************************************************************************************************************
   //
   // Method: Vector2D
   //
   // Description:
   //    Constructor for the vector to set member variables to their default values.
   //
   // Arguments:
   //    aComponentX - The X component of the vector.
   //    aComponentY - The Y component of the vector.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Vector2D::Vector2D(const float aComponentX, const float aComponentY) :
      mComponentX(aComponentX), mComponentY(aComponentY)
   {
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D operator+(Vector2D aLeftVector, const Vector2D aRightVector)
   {
      return aLeftVector.Add(aRightVector);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D operator-(Vector2D aLeftVector, const Vector2D aRightVector)
   {
      return aLeftVector.Subtract(aRightVector);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D operator*(Vector2D aLeftVector, const Vector2D aRightVector)
   {
      return aLeftVector.Multiply(aRightVector);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D operator/(Vector2D aLeftVector, const Vector2D aRightVector)
   {
      return aLeftVector.Divide(aRightVector);
   }

   //******************************************************************************************************************
   //
   // Method: operator+=
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
   //******************************************************************************************************************
   Vector2D& Vector2D::operator+=(const Vector2D& aRightVector)
   {
      return Add(aRightVector);
   }

   //******************************************************************************************************************
   //
   // Method: operator-=
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
   //******************************************************************************************************************
   Vector2D& Vector2D::operator-=(const Vector2D& aRightVector)
   {
      return Subtract(aRightVector);
   }

   //******************************************************************************************************************
   //
   // Method: operator*=
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
   //******************************************************************************************************************
   
   Vector2D& Vector2D::operator*=(const Vector2D& aRightVector)
   {
      return Multiply(aRightVector);
   }

   //******************************************************************************************************************
   //
   // Method: operator/=
   //
   // Description:
   //    Overrides the /= operator and returns the division of this vector to this vector. 
   //
   // Arguments:
   //    aRightVector - The right side of operator that is dividing to this vector.
   //
   // Return:
   //    Returns the division of this vector and the passed in vector.
   //
   //******************************************************************************************************************
   
   Vector2D& Vector2D::operator/=(const Vector2D& aRightVector)
   {
      return Divide(aRightVector);
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Vector2D::GetComponentX()
   {
      return mComponentX;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Vector2D::GetComponentY()
   {
      return mComponentY;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   float Vector2D::GetMagnitude()
   {
      return sqrtf(powf(fabsf(mComponentX), SQUARED) +
                   powf(fabsf(mComponentY), SQUARED));
   }

   //******************************************************************************************************************
   //
   // Method: GetNormalized
   //
   // Description:
   //    Returns the normalized x and y values of the vector. The nromalized values of these is the assumption that
   //    magnitude is of lenght 1.0 pixel.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   Vector2D Vector2D::GetNormalized()
   {
      float length = GetMagnitude();
      return Vector2D(mComponentX / length, mComponentY / length);
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
   //******************************************************************************************************************
   Vector2D& Vector2D::Add(const Vector2D& aVector)
   {
      mComponentX += aVector.mComponentX;
      mComponentY += aVector.mComponentY;

      return *this;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D& Vector2D::Subtract(const Vector2D& aVector)
   {
      mComponentX -= aVector.mComponentX;
      mComponentY -= aVector.mComponentY;

      return *this;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D& Vector2D::Multiply(const Vector2D& aVector)
   {
      mComponentX *= aVector.mComponentX;
      mComponentY *= aVector.mComponentY;

      return *this;
   }

   //******************************************************************************************************************
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
   //******************************************************************************************************************
   Vector2D& Vector2D::Divide(const Vector2D& aVector)
   {
      mComponentX /= aVector.mComponentX;
      mComponentY /= aVector.mComponentY;

      return *this;
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}