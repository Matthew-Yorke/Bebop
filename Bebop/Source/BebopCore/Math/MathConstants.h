//*********************************************************************************************************************
//
// File: MathConstants.h
//
// Description:
//    This files handles all the constants for the math namespace.
//
//*********************************************************************************************************************

#ifndef MathConstants_H
#define MathConstants_H

#define _USE_MATH_DEFINES
#include <cmath>

namespace Bebop { namespace Math
{
   const float PI = 3.14159265358979323846F;

   // The radians of a complete circle.
	const float CIRCLE_RADIANS = 2 * static_cast<float>(PI);

   // Conversion from degrees to radians.
   const float RADIANS_CONVERSION = static_cast<float>(PI) / 180.0F;

   // Conversion from degrees to radians.
   const float DEGREES_CONVERSION = 180.0F / static_cast<float>(PI);

   // The number of columns and rows in a 2D matrix.
   const int MATRIX_SIZE_2D = 2;

   // The value for the degrees at point 0.
   const float DEGREES_ZERO = 0.0F;

   // The value for degrees at point 360.
   const float DEGREES_THREE_SIXTY = 360.0F;

   // The value of incrementing to the next degree.
   const float DEGREES_INCREMENT = 1.0F;

   // The value used when finding the next item in an iterator.
   const int NEXT_ITERATOR_VALUE = 1;

   // The minimum size of a collision vector needed to check for collisions.
   const int MINIMUM_COLLISION_VECTOR_SIZE = 2;
}}

#endif // MathConstants_H