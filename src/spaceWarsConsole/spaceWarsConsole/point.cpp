#include "point.h"



point::point()
{
    point(0, 0);
}

point::point(float x, float y)
{
    setX(x);
    setY(y);
}

bool operator ==(const point &p1, const point &p2)
{
    return (p1.x()==p2.x())&&(p1.y()==p2.y());
}


const point operator-(const point &p1, const point &p2)
{
    return point((p1.x()-p2.x()),(p1.y()-p2.y()));
}

const point operator+ (const point &p1, const point &p2)
{
    return point((p1.x()+p2.x()),(p1.y()+p2.y()));
}
