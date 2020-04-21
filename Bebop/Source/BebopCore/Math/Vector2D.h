//*********************************************************************************************************************
//
// File: Vector2D.h
//
// Description:
//    This class handles functionality for a 2D vector. Direction is based on the positive and negative values of the
//    x and y components. A positive X component is movement to the right and negative is movement to the left. A
//    positive Y component is movement downwards and negative is movement upwards.
//
//*********************************************************************************************************************

#ifndef Vector2D_H
#define Vector2D_H

namespace Bebop { namespace Math
{
   template<class T> class Vector2D;
   template<class T> Vector2D<T> operator+(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);
   template<class T> Vector2D<T> operator-(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);
   template<class T> Vector2D<T> operator*(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);
   template<class T> Vector2D<T> operator/(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);

   template<class T>
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
         Vector2D(const T aComponentX, const T aComponentY);

         //************************************************************************************************************
         //
         // Method: operator+
         //
         // Description:
         //    Overrides the + operator and returns the addition of this vector to another.  
         //
         // Arguments:
         //    aLeftVector  - The left side of the operator that is being added from.
         //    aRightVector - The right side of operator that is adding to the left.
         //
         // Return:
         //    Returns the addition of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D<T> operator+ <>(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);

         //************************************************************************************************************
         //
         // Method: operator-
         //
         // Description:
         //    Overrides the - operator and returns the subtraction of this vector to another.  
         //
         // Arguments:
         //    aLeftVector  - The left side of the operator that is being subtracted from.
         //    aRightVector - The right side of operator that is subtracting to the left.
         //
         // Return:
         //    Returns the subtraction of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D<T> operator- <>(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);

         //************************************************************************************************************
         //
         // Method: operator*
         //
         // Description:
         //    Overrides the * operator and returns the multiplication of this vector to another.
         //
         // Arguments:
         //    aLeftVector  - The left side of the operator that is being multiplied from.
         //    aRightVector - The right side of operator that is multiplying to the left.
         //
         // Return:
         //    Returns the multiplication of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D<T> operator* <>(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);

         //************************************************************************************************************
         //
         // Method: operator/
         //
         // Description:
         //    Overrides the / operator and returns the division of this vector to another. 
         //
         // Arguments:
         //    aLeftVector  - The left side of the operator that is being divided from.
         //    aRightVector - The right side of operator that is dividing to the left.
         //
         // Return:
         //    Returns the devision of two vectors.
         //
         //************************************************************************************************************
         friend Vector2D<T> operator/ <>(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector);

         //************************************************************************************************************
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
         //************************************************************************************************************
         Vector2D<T>& operator+=(const Vector2D<T>& aRightVector);

         //************************************************************************************************************
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
         //************************************************************************************************************
         Vector2D<T>& operator-=(const Vector2D<T>& aRightVector);

         //************************************************************************************************************
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
         //************************************************************************************************************
         Vector2D<T>& operator*=(const Vector2D<T>& aRightVector);

         //************************************************************************************************************
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
         //************************************************************************************************************
         Vector2D<T>& operator/=(const Vector2D<T>& aRightVector);

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
         T GetComponentX() const;

         //************************************************************************************************************
         //
         // Method: SetComponentX
         //
         // Description:
         //    Sets the X component of the vector.
         //
         // Arguments:
         //    aComponentX - The X-Componenet value to set.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetComponentX(const T aComponentX);

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
         T GetComponentY() const;

         //************************************************************************************************************
         //
         // Method: SetComponentY
         //
         // Description:
         //    Sets the Y component of the vector.
         //
         // Arguments:
         //    aComponentY - The Y-Componenet value to set.
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         void SetComponentY(const T aComponentY);

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
         T GetMagnitude() const;

         //************************************************************************************************************
         //
         // Method: GetNormalized
         //
         // Description:
         //    Returns the normalized x and y values of the vector. The normalized values of these is the assumption
         //    that magnitude is of length 1.0 pixel.
         //
         // Arguments:
         //    N/A
         //
         // Return:
         //    N/A
         //
         //************************************************************************************************************
         Vector2D<T> GetNormalized() const;

         //************************************************************************************************************
         //
         // Method: Dot
         //
         // Description:
         //    Returns the dot product using the passed in vector.
         //
         // Arguments:
         //    aOther - The vector being used for the dot product against this vector
         //
         // Return:
         //    Returns a float of the dot product of this vector against another vector.
         //
         //************************************************************************************************************
         float Dot(const Vector2D<T> aOther);

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
         Vector2D<T>& Add(const Vector2D<T>& aVector);

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
         Vector2D<T>& Subtract(const Vector2D<T>& aVector);

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
         Vector2D<T>& Multiply(const Vector2D<T>& aVector);

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
         Vector2D<T>& Divide(const Vector2D<T>& aVector);

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

         T mComponentX;

         T mComponentY;

   //******************************************************************************************************************
   // Member Variables - End
   //******************************************************************************************************************
   };

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
   template<class T>
   Vector2D<T>::Vector2D(const T aComponentX, const T aComponentY) :
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
   //    aLeftVector  - The left side of the operator that is being added from.
   //    aRightVector - The right side of operator that is adding to the left.
   //
   // Return:
   //    Returns the addition of two vectors.
   //
   //******************************************************************************************************************
   template<class T>
   Vector2D<T> operator+(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector)
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
   //    aLeftVector  - The left side of the operator that is being subtracted from.
   //    aRightVector - The right side of operator that is subtracting to the left.
   //
   // Return:
   //    Returns the subtraction of two vectors.
   //
   //******************************************************************************************************************
   template<class T>
   Vector2D<T> operator-(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector)
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
   //    aLeftVector  - The left side of the operator that is being multiplied from.
   //    aRightVector - The right side of operator that is multiplying to the left.
   //
   // Return:
   //    Returns the multiplication of two vectors.
   //
   //******************************************************************************************************************
   template<class T>
   Vector2D<T> operator*(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector)
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
   //    aLeftVector  - The left side of the operator that is being divided from.
   //    aRightVector - The right side of operator that is dividing to the left.
   //
   // Return:
   //    Returns the devision of two vectors.
   //
   //******************************************************************************************************************
   template<class T>
   Vector2D<T> operator/(Vector2D<T> aLeftVector, const Vector2D<T> aRightVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T>& aRightVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::operator-=(const Vector2D<T>& aRightVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::operator*=(const Vector2D<T>& aRightVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::operator/=(const Vector2D<T>& aRightVector)
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
   template<class T>
   T Vector2D<T>::GetComponentX() const
   {
      return mComponentX;
   }

   //******************************************************************************************************************
   //
   // Method: SetComponentX
   //
   // Description:
   //    Sets the X component of the vector.
   //
   // Arguments:
   //    aComponentX - The X-Componenet value to set.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   template<class T>
   void Vector2D<T>::SetComponentX(const T aComponentX)
   {
      mComponentX = aComponentX;
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
   template<class T>
   T Vector2D<T>::GetComponentY() const
   {
      return mComponentY;
   }

   //******************************************************************************************************************
   //
   // Method: SetComponentY
   //
   // Description:
   //    Sets the Y component of the vector.
   //
   // Arguments:
   //    aComponentX - The Y-Componenet value to set.
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   template<class T>
   void Vector2D<T>::SetComponentY(const T aComponentY)
   {
      mComponentY = aComponentY;
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
   template<class T>
   T Vector2D<T>::GetMagnitude() const
   {
      return sqrtf((mComponentX * mComponentX) + (mComponentY * mComponentY));
   }

   //******************************************************************************************************************
   //
   // Method: GetNormalized
   //
   // Description:
   //    Returns the normalized x and y values of the vector. The normalized values of these is the assumption that
   //    magnitude is of length 1.0 pixel.
   //
   // Arguments:
   //    N/A
   //
   // Return:
   //    N/A
   //
   //******************************************************************************************************************
   template<class T>
   Vector2D<T> Vector2D<T>::GetNormalized() const
   {
      float length = GetMagnitude();
      return Vector2D(mComponentX / length, mComponentY / length);
   }

   //******************************************************************************************************************
   //
   // Method: Dot
   //
   // Description:
   //    Returns the dot product using the passed in vector.
   //
   // Arguments:
   //    aOther - The vector being used for the dot product against this vector
   //
   // Return:
   //    Returns a float of the dot product of this vector against another vector.
   //
   //******************************************************************************************************************
   template<class T>
   float Vector2D<T>::Dot(const Vector2D<T> aOther)
   {
      return mComponentX * aOther.GetComponentX() + mComponentY * aOther.GetComponentY();
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
   template<class T>
   Vector2D<T>& Vector2D<T>::Add(const Vector2D<T>& aVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::Subtract(const Vector2D<T>& aVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::Multiply(const Vector2D<T>& aVector)
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
   template<class T>
   Vector2D<T>& Vector2D<T>::Divide(const Vector2D<T>& aVector)
   {
      mComponentX /= aVector.mComponentX;
      mComponentY /= aVector.mComponentY;

      return *this;
   }

//*********************************************************************************************************************
// Private Methods - End
//*********************************************************************************************************************
}}

#endif // Vector2D_H