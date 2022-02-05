#include <math.h>
#include "GEO_Position.h"

double grad(short grad, double min)
{
    return (double)grad+min/60.0;
}

double distanceX(PositionT p1, PositionT p2)
{
    double mLatGrad = (p1.latgrad+p2.latgrad)/2.0;
    return 111.3 * cos(M_PI/180.0*mLatGrad) * (p1.lengrad-p2.lengrad);
}


double distanceY(PositionT p1, PositionT p2)
{
    return 111.3 * (p1.latgrad - p2.latgrad);
}
