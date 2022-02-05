#ifndef VR_MODEL_H_INCLUDED
#define VR_MODEL_H_INCLUDED

#define MAX_COLUMN_AP_FILE 120
#define MAX_AIRFIELD 500

#include "GEO_Position.h"
typedef char ICAOT[5];
typedef char AirfieldNameT[43];

typedef struct{
    ICAOT icao;
    AirfieldNameT name;
    PositionT position;
}AirfieldT;

typedef struct{
    int number;
    AirfieldT fp[MAX_AIRFIELD];
}ListAirportsT;

int load_airfield_datas(char* file_name, ListAirportsT* fpl);
int load_text_file(char* file_name, char text[][MAX_COLUMN_AP_FILE]);
int convert_string_to_airfield(char* s, AirfieldT* fp);


#endif // VR_MODEL_H_INCLUDED
