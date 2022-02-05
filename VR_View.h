#ifndef VR_VIEW_H_INCLUDED
#define VR_VIEW_H_INCLUDED

#define WIDTH_WINDOW 700          // Width of the window for the display of the map (unit: pixels)
#define HIGH_WINDOW  718         // Height of the window for the display of the map (unit: pixels)
#define MAP_EDGE_LENGTH 100     // Standard size of the map area to be displayed (edge length in km)

#include "VR_Model.h"

void clrscr();
void initialize_map();
void remove_map();
void show_map(ListAirportsT fpl, PositionT middle, double scale);
void List_airports(ListAirportsT fpl);

#endif // VR_VIEW_H_INCLUDED
