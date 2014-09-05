#ifndef GRAPHICOBJECTS_H
#define GRAPHICOBJECTS_H
#include "graphicchar.h"
#include <QList>


#define DIR_RIGHT 0
#define DIR_LEFT 2
#define DIR_UP 1
#define DIR_DOWN 3


class graphicObjects
{
private:


    //Object position  (top left corner position)
    point _pos;



    //Moving field or universe limits
    int _fieldLimtRight, _fieldLimitLeft, _fieldLimitTop, _fieldLimitBot;



    //Object limits
    int _edgeRight, _edgeLeft, _edgeTop, _edgeBot;



protected:

    //This function initializes the object.
    //This function must be executed in any constructor
    void inititObj(point pos, float speed, char dir, int fLR, int fLL, int fLT, int fLB);


    //This function fills the hit areas with the same positions of the graphics chars
    void fillHitArea();


    // one graphic for each direction
    QList <graphicChar> _graphRight, _graphLeft, _graphUp, _graphDown;

    //Colision power
    int _hitPower;

    //Hit area for each direction
    QList <point> _hitAreaRight, _hitAreaLeft, _hitAreaUp, _hitAreaDown;

    //Object speed
    float _speed;

    // 0:RIGHT,1:UP,2:LEFT,3:DOWN
    char _direction;

public:
    /// \brief  Initialize object with empty parameters
    graphicObjects();

    /// \brief  Initialize object with given parameters
    ///
    ///  \param[in] pos     object position
    ///  \param[in] speed   object speed
    ///  \param[in] dir     object direction
    ///  \param[in] fLR     right field limit
    ///  \param[in] fLL     left field limit
    ///  \param[in] fLT     top field limit
    ///  \param[in] fLB     bottom field limit
    graphicObjects(point pos, float speed, char dir, int fLR, int fLL, int fLT, int fLB);




    int paint();
    int tic(double time);//time en milisegundos
    int checkHit(point p);
    int checkHit(const QList<point> &points);

    //Set functions
    void setPos(point p);
    void setPos(int x, int y);
    void setSpeed(float s);
    void setFieldLimits(int R, int L, int T, int B);
    bool setDir(char dir);

};

#endif // GRAPHICOBJECTS_H
