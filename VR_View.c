#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include "VR_View.h"
#include "VR_Model.h"
#include "GEO_Position.h"

void clrscr()
{
    system("cls");
}

void initialize_map()
{
    initwindow(WIDTH_WINDOW, HIGH_WINDOW,"Virtual_Radar",0,0, FALSE, FALSE);
    setbkcolor(BLACK);
    clearviewport();
}

void remove_map()
{
    closegraph();
}

void plotAirfield(int x, int y, AirfieldT fp)
{
    setcolor(WHITE);
    circle(x,y,3);
//  settextjustify(LEFT_TEXT,TOP_TEXT);
//  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtextxy(x-3,y+3,&(fp.icao[2]));
}

void show_map(ListAirportsT fpl, PositionT middle, double scale)
{
    int i;
    int row,colunm;
    double x,y;
    double edge_length = scale * MAP_EDGE_LENGTH;

    // 1. Display screen
    clearviewport();

    // 2. Drawing flight locations
    i = 0; // Variable number of seats
    while(i<fpl.number)
    {
        // 2.1 Mercator transformation
        x = distanceX(fpl.fp[i].position,middle);
        y = distanceY(fpl.fp[i].position,middle);

        // 2.2 Calculate rows and columns
        colunm = (double)(WIDTH_WINDOW*x/edge_length)+(WIDTH_WINDOW/2);
        row = (HIGH_WINDOW/2) - (double)(HIGH_WINDOW*y/edge_length);

        // 2.3 Clipping and drawing
        if(colunm > 0 && colunm < HIGH_WINDOW && row >0 && row < WIDTH_WINDOW)
        {
            plotAirfield(colunm-30, row-25, fpl.fp[i]); // col-30 and row-25 is done to center graphic
        }
        // 2.4 Raise the meter
        i++;
    }

}

void List_airports(ListAirportsT fpl)
{
    int i;
    char c;
    clrscr();

    printf("%-4s | %-5s | %7s | %7s | %-s\n","No.","ICAO","Latitud","Length","Location");
    printf("-----|-------|---------|---------|----------------------------------\n");
    i=0;
    while(i<fpl.number)
    {

        printf("%-4i | %-5s | %7.2f | %7.2f | %-s\n",
               i+1,
               fpl.fp[i].icao,
               fpl.fp[i].position.latgrad,
               fpl.fp[i].position.lengrad,
               fpl.fp[i].name
               );
        i++;
		if ( i % 20 == 0 )
		{
		    printf("\ncontinue with ENTER");
		    fflush(stdin);
			c=getchar();
			clrscr();
            printf("%-4s | %-5s | %7s | %7s | %-s\n","No.","ICAO","Latitud","Length","Location");
            printf("-----|-------|---------|---------|----------------------------------\n");
        }
    }
    printf("\nExit with ENTER");
	c=getchar();
}
