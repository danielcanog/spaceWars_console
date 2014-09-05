#ifndef SHIP_H
#define SHIP_H
#include "graphicobjects.h"



class ship : public graphicObjects
{
private:
    //This function initializes the object.
    //This function must be executed in any constructor
    void initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB);

    //Speed parameters
    static const float _SPEED_STEEP;
    static const float _SPEED_MAX;
    static const float _SPEED_MIN;

    //Key comands storing variables
    int _sUp,_sDown,_turnRight,_turnLeft,_fire1,_fire2;

public:
    ship();
    ship(point pos, float speed, char dir, int flR, int flL, int flT, int flB);

    /// \brief Speed up. Increment speed by _SPEED_STEEP, until reach the _SPEED_MAX limit.
    void speedUP();

    /// \brief Speed down. Reduce speed by _SPEED_STEEP, until reach the _SPEED_MIN limit.
    void speedDown();

    /// \brief  Turn 90 degrees to the right.
    void turnRight();

    /// \brief  Turn 90 degrees to the left.
    void turnLeft();

    /// \brief  Fire type 1
    void fire1();

    /// \brief  Fire type 2
    void fire2();

    /// \brief  Configure the recognoised comands.
    ///
    /// \param[in]  speedUp     Key to activate the function 'speedUP()'
    /// \param[in]  speedDown   Key to activate the function 'speedDown()'
    /// \param[in]  turnRight   Key to activate the function 'turnRight()'
    /// \param[in]  turnLeft    Key to activate the function 'turnLeft()'
    /// \param[in]  fire1       Key to activate the function 'fire1()'
    /// \param[in]  fire2       Key to activate the function 'fire2()'
    ///
    ///  \return 0 if all OK. errCode if an error occur.
    int confCmd(int speedUp,int speedDown,int turnRight, int turnLeft, int fire1, int fire2 );

    /// \brief  Recive a comand.
    ///         Recieve a comand, check if is a recongoised comand and execute it.
    ///         !!The comands must be configured with the 'confCmd()' function before calling this function.
    /// \param[in]  cmd Comand to execute. This comand are compared against the comands configured with the function 'confCmd'.
    ///
    /// \return  1 if the comand has been rocognoised
    ///          0 if the comand is recived but is not a recognoised comand
    ///         -1 if the comands hasn't been configured
    int recvCmd(int cmd);
};

#endif // SHIP_H
