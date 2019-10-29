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
   // The radians of a complete circle.
	const float CIRCLE_RADIANS = 2 * static_cast<float>(M_PI);

   // Conversion from degrees to radians.
   const float RADIANS_CONVERSION = static_cast<float>(M_PI) / 180.0F;

   // The number of columns and rows in a 2D matrix.
   const int MATRIX_SIZE_2D = 2;

   // The value to square another value.
   const float SQUARED = 2.0F;
}}

#endif // MathConstants_H