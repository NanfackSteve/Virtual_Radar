#ifndef GEO_POSITION_H_INCLUDED
#define GEO_POSITION_H_INCLUDED

#define M_PI		3.14159265358979323846

typedef double LengthT;
typedef double LatitudeT;

typedef struct{
    LatitudeT latgrad;
    LengthT lengrad;
}PositionT;

double grad(short grad, double min);
double distanceX(PositionT p1, PositionT p2);
double distanceY(PositionT p1, PositionT p2);

#endif // GEO_POSITION_H_INCLUDED
