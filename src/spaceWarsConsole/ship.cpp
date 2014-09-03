#include "ship.h"
#include "consoleTools/basicGraphic/basicgraphic.h"

void ship::initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    //Initialize graphic Object
    graphicObjects::inititObj(pos,speed,dir,flR,flL,flT,flB);

    //Redefine Graphics
    //Right Graphic
    _graphRight.clear();
    _graphRight.append(graphicChar(point(0,0),'|',BG_GREEN));
    _graphRight.append(graphicChar(point(1,0),'\\',BG_GREEN));
    _graphRight.append(graphicChar(point(2,0),'_',BG_GREEN));
    _graphRight.append(graphicChar(point(0,1),'>',BG_CYAN));
    _graphRight.append(graphicChar(point(1,1),'X',BG_RED));
    _graphRight.append(graphicChar(point(2,1),'_',BG_GREEN));
    _graphRight.append(graphicChar(point(3,1),'>',BG_GREEN));
    _graphRight.append(graphicChar(point(0,2),'|',BG_GREEN));
    _graphRight.append(graphicChar(point(1,2),'/',BG_GREEN));
    //Left Graphic
    _graphLeft.clear();
    _graphLeft.append(graphicChar(point(1,0),'_',BG_GREEN));
    _graphLeft.append(graphicChar(point(2,0),'/',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,0),'|',BG_GREEN));
    _graphLeft.append(graphicChar(point(0,1),'<',BG_GREEN));
    _graphLeft.append(graphicChar(point(2,1),'X',BG_RED));
    _graphLeft.append(graphicChar(point(1,1),'_',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,1),'<',BG_CYAN));
    _graphLeft.append(graphicChar(point(2,2),'\\',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,2),'|',BG_GREEN));
    //Down Graphic
    _graphDown.clear();
    _graphDown.append(graphicChar(point(0,0),'-',BG_GREEN));
    _graphDown.append(graphicChar(point(1,0),'v',BG_CYAN));
    _graphDown.append(graphicChar(point(2,0),'-',BG_GREEN));
    _graphDown.append(graphicChar(point(0,1),'\\',BG_GREEN));
    _graphDown.append(graphicChar(point(1,1),'X',BG_RED));
    _graphDown.append(graphicChar(point(2,1),'/',BG_GREEN));
    _graphDown.append(graphicChar(point(0,2),'|',BG_GREEN));
    _graphDown.append(graphicChar(point(2,2),'|',BG_GREEN));
    _graphDown.append(graphicChar(point(1,3),'v',BG_GREEN));
    //Up graphic
    _graphUp.clear();
    _graphUp.append(graphicChar(point(0,3),'-',BG_GREEN));
    _graphUp.append(graphicChar(point(1,3),'^',BG_CYAN));
    _graphUp.append(graphicChar(point(2,3),'-',BG_GREEN));
    _graphUp.append(graphicChar(point(0,2),'/',BG_GREEN));
    _graphUp.append(graphicChar(point(1,2),'X',BG_RED));
    _graphUp.append(graphicChar(point(2,2),'\\',BG_GREEN));
    _graphUp.append(graphicChar(point(0,1),'|',BG_GREEN));
    _graphUp.append(graphicChar(point(2,1),'|',BG_GREEN));
    _graphUp.append(graphicChar(point(1,0),'^',BG_GREEN));

    //Refill hit areas
    fillHitArea();

    //Set hit power
    _hitPower=2;
}

ship::ship()
{
}

ship::ship(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,speed,dir,flR,flL,flT,flB);
}



