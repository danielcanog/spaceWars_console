#ifndef POINT_H
#define POINT_H

class point
{
private:
    float _posX;
    float _posY;

public:
    point();
    point(float x, float y);

    //Get and set functions for x and y
    void setX(const float & x){_posX = x;}
    float x() const{return _posX;}
    int xInt() const {return static_cast<int>(_posX);}


    float y() const {return _posY;}
    int yInt() const {return static_cast<int>(_posY);}
    void setY(const float & y){_posY = y;}

};


//Sobrecarga de operadores
bool operator == (const point& p1,  const point& p2);
const point operator-(const point & p1, const point & p2);
const point operator+ (const point & p1, const point & p2);


#endif // POINT_H
