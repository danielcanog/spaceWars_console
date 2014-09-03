#include "graphicobjects.h"

void graphicObjects::inititObj(point pos, float speed, char dir, int fLR, int fLL, int fLT, int fLB)
{
    //Initialize a empty graphic object
    //Create object graphics
    //Right Graphic
    _graphRight.append(graphicChar(point(0,0),'?'));
    _graphRight.append(graphicChar(point(1,0),'>'));
    //Left Graphic
    _graphLeft.append(graphicChar(point(0,0),'<'));
    _graphLeft.append(graphicChar(point(1,0),'?'));
    //Down Graphic
    _graphDown.append(graphicChar(point(0,0),'?'));
    _graphDown.append(graphicChar(point(0,1),'V'));
    //Up Graphic
    _graphUp.append(graphicChar(point(0,0),'^'));
    _graphUp.append(graphicChar(point(0,1),'?'));

    //Create hit area (according to graphic)
    //Right Hit Area
    _hitAreaRight.append(point(0,0));
    _hitAreaRight.append(point(1,0));
    //Left Hit Area
    _hitAreaLeft.append(point(0,0));
    _hitAreaLeft.append(point(1,0));
    //Down Hit Area
    _hitAreaDown.append(point(0,0));
    _hitAreaDown.append(point(0,1));
    //Up Hit Area
    _hitAreaUp.append(point(0,0));
    _hitAreaUp.append(point(0,1));

    //define hit power
    _hitPower=1;


    //Fill it with the given parametters
    setDir(dir);
    setSpeed(speed);
    setPos(pos);
    setFieldLimits(fLR,fLL,fLT,fLB);
}

void graphicObjects::fillHitArea()
{
    _hitAreaRight.clear();
    for(int i=0;i<_graphRight.size();i++)
        _hitAreaRight.append(_graphRight[i].pos());

    _hitAreaLeft.clear();
    for(int i=0; i<_graphLeft.size(); i++)
        _hitAreaLeft.append(_graphLeft[i].pos());

    _hitAreaDown.clear();
    for(int i=0; i<_graphDown.size();i++)
        _hitAreaDown.append(_graphDown[i].pos());

    _hitAreaUp.clear();
    for(int i=0; i<_graphUp.size();i++)
        _hitAreaUp.append(_graphUp[i].pos());

}

graphicObjects::graphicObjects()
{
    //Set default parameters
    inititObj(point(0,0), 0, DIR_LEFT, 0, 0, 0, 0);
}


graphicObjects::graphicObjects(point pos, float speed, char dir, int fLR, int fLL, int fLT, int fLB)
{
    inititObj(pos, speed, dir, fLR, fLL, fLT, fLB);
}


int graphicObjects::paint()
{
    switch(_direction)
    {
    case DIR_LEFT:
        for(int i=0;i<_graphLeft.size();i++)
            _graphLeft[i].paint(_pos);
        break;
    case DIR_RIGHT:
        for (int i=0; i<_graphRight.size();i++)
            _graphRight[i].paint(_pos);
        break;
    case DIR_DOWN:
        for(int i=0; i<_graphDown.size();i++)
            _graphDown[i].paint(_pos);
        break;
    case DIR_UP:
        for(int i=0;i<_graphUp.size();i++)
            _graphUp[i].paint(_pos);
        break;
    default:
        return -1;//la direccion no es valida

    }

    return 0;
}

int graphicObjects::tic(double time)
{
    point newPos;

  //Intenta moverse
    switch(_direction)
    {
    case DIR_LEFT:
        newPos.setX(_pos.x()-_speed*time);
        newPos.setY(_pos.y());
        break;

    case DIR_RIGHT:
        newPos.setX(_pos.x()+ _speed*time);
        newPos.setY(_pos.y());
        break;

    case DIR_DOWN:
        newPos.setX(_pos.x());
        newPos.setY(_pos.y()+_speed*time);
        break;
    case DIR_UP:
        newPos.setX(_pos.x());
        newPos.setY(_pos.y()-_speed*time);
    }

    //verify if the object is in the field
    bool objInside=true;

    switch(_direction)
    {
    case DIR_LEFT:
        if(newPos.xInt() +_edgeLeft <= _fieldLimitLeft)
            objInside=false;
        break;
    case DIR_RIGHT:
        if(newPos.xInt() + _edgeRight >= _fieldLimtRight)
            objInside=false;
        break;
    case DIR_DOWN:
        if(newPos.yInt()+_edgeBot >=_fieldLimitBot)
            objInside=false;
        break;
    case DIR_UP:
        if(newPos.yInt()<=_fieldLimitTop)
            objInside=false;
        break;
    default:
        return -1;
        break;
    }

    //If objInside==true
    if(objInside==true)
    {
        _pos=newPos;
    }
    else
    {
        switch(_direction)
        {
        case DIR_RIGHT:
            _pos.setX(_fieldLimtRight-_edgeRight-1);
            break;
        case DIR_LEFT:
            _pos.setX(_fieldLimitLeft+1);
            break;
        case DIR_DOWN:
            _pos.setY(_fieldLimitBot-_edgeBot -1);
            break;
        case DIR_UP:
            _pos.setY(_fieldLimitTop+1);
            break;
        }

        _speed=0;
    }

    return 0;
}

int graphicObjects::checkHit(point p)
{

    p.setX(p.x()-_pos.x());//transformar de global a local
    p.setY(p.y()-_pos.x());

    ///Grabbing reference of current hit Area
    QList<point>* currentHitArea;
    switch(_direction)
    {
    case DIR_RIGHT:
        currentHitArea=&_hitAreaRight;
        break;
    case DIR_LEFT:
        currentHitArea=&_hitAreaLeft;
        break;
    case DIR_DOWN:
        currentHitArea=&_hitAreaDown;
        break;
    case DIR_UP:
        currentHitArea=&_hitAreaUp;
        break;
    }

    for(int i=0;i<currentHitArea->size();i++){
        if(p==currentHitArea->at(i))
            return 1;
    }
    return 0;

}

int graphicObjects::checkHit(const QList<point> &points)
{
    ///Check point to point
    int countPoints=0;
    for(int i=0;i<points.size();i++)
        countPoints += checkHit(points[i]);

    return countPoints;

}

void graphicObjects::setPos(point p)
{
    _pos = p;
}

void graphicObjects::setPos(int x, int y)
{
    setPos(point(x,y));
}

void graphicObjects::setSpeed(float s)
{
    _speed=s;
}

void graphicObjects::setFieldLimits(int R, int L, int T, int B)
{
    _fieldLimtRight=R;
    _fieldLimitLeft=L;
    _fieldLimitTop=T;
    _fieldLimitBot=B;
}

bool graphicObjects::setDir(char dir)
{
    //Validate dir parameter
    if (dir>3 || dir<0)
       return false;

    //Get actual hit area reference
    QList<point>* currentHitArea;
    switch(dir)
    {
    case DIR_RIGHT:
        currentHitArea=&_hitAreaRight;
        break;
    case DIR_LEFT:
        currentHitArea=&_hitAreaLeft;
        break;
    case DIR_DOWN:
        currentHitArea=&_hitAreaDown;
        break;
    case DIR_UP:
        currentHitArea=&_hitAreaUp;
        break;
    }

    //Validate hit area
    if(currentHitArea->size()==0)
        return false;

    //Find edges
    float maxX=currentHitArea->at(0).x();
    float minX=currentHitArea->at(0).x();
    float maxY=currentHitArea->at(0).y();
    float minY=currentHitArea->at(0).y();

    for (int i=0; i<currentHitArea->size();i++)
    {
        if(currentHitArea->at(i).x()>maxX)
            maxX=currentHitArea->at(i).x();
        if(currentHitArea->at(i).x()<minX)
            minX=currentHitArea->at(i).x();
        if(currentHitArea->at(i).y()>maxY)
            maxY=currentHitArea->at(i).y();
        if(currentHitArea->at(i).y()<minY)
            minY=currentHitArea->at(i).y();
    }
    _edgeRight=maxX;
    _edgeLeft=minX;
    _edgeBot=maxY;
    _edgeTop=minY;

    //Update direction
    _direction=dir;

    return true;
}




















