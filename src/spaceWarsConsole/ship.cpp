#include "ship.h"

//Speed units: carr/milisecond
const float ship::_SPEED_STEEP=(float)0.001;
const float ship::_SPEED_MAX=(float)0.05;
const float ship::_SPEED_MIN= (float)0;

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

    //Clear comands config vars
    _sUp = 0;
    _sDown = 0;
    _turnLeft = 0;
    _turnRight = 0;
    _fire1 = 0;
    _fire2 = 0;

}

ship::ship()
{
}

ship::ship(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,speed,dir,flR,flL,flT,flB);
}


void ship::speedUP()
{
    _speed += _SPEED_STEEP;
    //Verify speed limit
    if(_speed>_SPEED_MAX)
        _speed = _SPEED_MAX;
}

void ship::speedDown()
{
    _speed -= _SPEED_STEEP;
    //Verify speed limit
    if(_speed < _SPEED_MIN)
        _speed = _SPEED_MIN;
}

void ship::turnRight()
{
    switch(_direction)
    {
    case DIR_RIGHT:
        _direction = DIR_DOWN;
        break;
    case DIR_DOWN:
        _direction = DIR_LEFT;
        break;
    case DIR_LEFT:
        _direction = DIR_UP;
        break;
    case DIR_UP:
        _direction = DIR_RIGHT;
        break;
     }

}

void ship::turnLeft()
{
    switch(_direction)
    {
    case DIR_RIGHT:
        _direction = DIR_UP;
        break;
    case DIR_DOWN:
        _direction = DIR_RIGHT;
        break;
    case DIR_LEFT:
        _direction = DIR_DOWN;
        break;
    case DIR_UP:
        _direction = DIR_LEFT;
        break;
    }
}

void ship::fire1()//disparo Tipo 1
{

}

void ship::fire2()//disparo tipo 2
{

}

int ship::confCmd(int speedUp, int speedDown, int turnRight, int turnLeft, int fire1, int fire2)
{
    //Validate parameters
    if(!(speedUp && speedDown && turnLeft && turnRight && fire1 && fire2))
            return -1;

    //Get configuration
    _sUp = speedUp;
    _sDown = speedDown;
    _turnRight = turnRight;
    _turnLeft = turnLeft;
    _fire1 = fire1;
    _fire2 = fire2;

    return 0;
}

int ship::recvCmd(int cmd)
{
    //Validate configured comands
    if(!(_sUp && _sDown && _turnLeft && _turnRight && _fire1 && _fire2))
        return -1;

    //Interpret comand
    if(cmd == _sUp)
        speedUP();
    else if(cmd == _sDown)
        speedDown();
    else if(cmd == _turnLeft)
        turnLeft();
    else if(cmd == _turnRight)
        turnRight();
    else if(cmd == _fire1)
        fire1();
    else if(cmd == _fire2)
        fire2();
    else
        return 0;   //Unrecognoised comand

    //Recognoised comand
    return 1;
}



