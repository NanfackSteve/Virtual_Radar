#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>

#include "GEO_Position.h"
#include "VR_Model.h"
#include "VR_View.h"



int main(int argc,char* argv[])
{
// Auxiliary variables
    int ret;

// Application variables
    char file_name[100] = "airport.dat";
    ListAirportsT airfields;
    PositionT POI = {51.5,10.0};

// 1 Loading airfield data
    ret = load_airfield_datas(file_name,&airfields);
    if(ret==0)
    {
        printf("ERROR !!! Airfield data could not be loaded. \n");
        return 0;
    }

// 2. Show flight locations
    List_airports(airfields);

// 3. Initialize the map
    initialize_map();

// 4. Show map
    show_map(airfields,POI, 9);

// 5. Waiting to quit
    ret = getchar();

// 6. Exit Graphic
    remove_map();

    return 1;
}
