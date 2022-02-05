#include <stdio.h>
#include <string.h>
#include "VR_Model.h"

int load_airfield_datas(char* file_name, ListAirportsT* fpl)
{
    char file_contents[MAX_AIRFIELD][MAX_COLUMN_AP_FILE];
    int i,data_sets_number,nbr=0;
    AirfieldT fp;

    data_sets_number = load_text_file(file_name,file_contents);
    if(data_sets_number==0)
        return 0;

    // konvertiere alle gelesenen Flugplatz-Zeichenketten in Flugplatz-Werte
    nbr = 0;
    for(i=0;i<data_sets_number;i++)
    {
        if(convert_string_to_airfield(file_contents[i],&fp))
        {
            fpl->fp[nbr] = fp;
            nbr++;
        }
    }
    fpl->number = nbr;
    return nbr;
}

int load_text_file(char* file_name, char text[][MAX_COLUMN_AP_FILE])
{
    FILE* myFile;
    int nbr=0;

    myFile=fopen(file_name,"r");
    if(!myFile)
    {
        printf("The file <%s> could not be opened.\n",file_name);
        return 0;
    }
    while(fgets(text[nbr++],MAX_COLUMN_AP_FILE,myFile));
    fclose(myFile);
    return nbr;
}

int convert_string_to_airfield(char* s, AirfieldT* fp)
{
    ICAOT icao;
    short lat_grad;
    double lat_min;
    short len_grad;
    double len_min;
    AirfieldNameT fpName;
    int ret;

    ret = sscanf(s,
                 "%4s , %hi,%lf,%hi,%lf,01/01/2002,13:59:00,%42[^,]",
                 icao,&lat_grad,&lat_min,&len_grad,&len_min,fpName);

    if(ret!=6)
    {
        printf("StringToAerodrome::Error in dataset\n%s\n",s);
        return 0;
    }
    else
    {
        strcpy(fp->icao,icao);
        fp->position.latgrad = grad(lat_grad,lat_min);
        fp->position.lengrad = grad(len_grad,len_min);
        strcpy(fp->name,fpName);
        return 1;
    }
}
