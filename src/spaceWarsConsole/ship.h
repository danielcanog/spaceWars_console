#ifndef SHIP_H
#define SHIP_H
#include "graphicobjects.h"

class ship : public graphicObjects
{
private:
    void initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
public:
    ship();
    ship(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
};

#endif // SHIP_H
