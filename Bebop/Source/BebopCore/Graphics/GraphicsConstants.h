//*********************************************************************************************************************
//
// File: GraphicsConstants.h
//
// Description:
//    This files handles all the constants for the graphics namespace.
//
//*********************************************************************************************************************

#ifndef GraphicsConstants_H
#define GraphicsConstants_H

#include <allegro5/allegro_primitives.h>

namespace Bebop { namespace Graphics
{
   // The maximum value for a color value.
	const unsigned int MAX_COLOR_VALUE = 255;

   // The color of the light source at the edge of the light's radius.
   const ALLEGRO_COLOR LIGHTS_EDGE_COLOR = al_map_rgba(0, 0, 0, 0);
}}

#endif // GraphicsConstants_H