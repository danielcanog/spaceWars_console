#include <iostream>
#include "consoleTools/basicGraphic/basicgraphic.h"
#include "graphicchar.h"
#include "graphicobjects.h"

int main(int argc, char *argv[])
{


    //Nave a dibujar
    // 01234567890
    //0      /|
    //1     < |
    //2  ___| |__/|
    //3<O___<==___|
    //4     | |
    //5     < |
    //6      \|

    graphicChar sheep[31];
    sheep[0] = graphicChar(point(0,3),'<',BG_GREEN);
    sheep[1] = graphicChar(point(1,3),'O',BG_DARK_RED);
    sheep[2] = graphicChar(point(2,2),'_',BG_GREEN);
    sheep[3] = graphicChar(point(2,3),'_',BG_GREEN);
    sheep[4] = graphicChar(point(3,2),'_',BG_GREEN);
    sheep[5] = graphicChar(point(3,3),'_',BG_GREEN);
    sheep[6] = graphicChar(point(4,2),'_',BG_GREEN);
    sheep[7] = graphicChar(point(4,3),'_',BG_GREEN);
    sheep[8] = graphicChar(point(5,1),'<',BG_RED);
    sheep[9] = graphicChar(point(5,2),'|',BG_GREEN);
    sheep[10]= graphicChar(point(5,3),'<',BG_RED);
    sheep[11]= graphicChar(point(5,4),'|',BG_GREEN);
    sheep[12] = graphicChar(point(5,5),'<',BG_RED);
    sheep[13] = graphicChar(point(6,0),'/',BG_GREEN);
    sheep[14] = graphicChar(point(6,3),'=',BG_DARK_RED);
    sheep[15] = graphicChar(point(6,6),'\\',BG_GREEN);
    sheep[16] = graphicChar(point(7,0),'|',BG_GREEN);
    sheep[17] = graphicChar(point(7,1),'|',BG_GREEN);
    sheep[18] = graphicChar(point(7,2),'|',BG_GREEN);
    sheep[19] = graphicChar(point(7,3),'=',BG_DARK_RED);
    sheep[20] = graphicChar(point(7,4),'|',BG_GREEN);
    sheep[21] = graphicChar(point(7,5),'|',BG_GREEN);
    sheep[22] = graphicChar(point(7,6),'|',BG_GREEN);
    sheep[23] = graphicChar(point(8,2),'_',BG_GREEN);
    sheep[24] = graphicChar(point(8,3),'_',BG_GREEN);
    sheep[25] = graphicChar(point(9,2),'_',BG_GREEN);
    sheep[26] = graphicChar(point(9,3),'_',BG_GREEN);
    sheep[27] = graphicChar(point(10,2),'/',BG_GREEN);
    sheep[28] = graphicChar(point(10,3),'_',BG_GREEN);
    sheep[29] = graphicChar(point(11,2),'|',BG_GREEN);
    sheep[30] = graphicChar(point(11,3),'|',BG_GREEN);


    //Paint the sheep
    point off(60,20);
    for(int i=0; i<31; i++)
        sheep[i].paint(off);

    bg::setColor();
    bg::gotoxy(0,40);




    QList<graphicObjects> pruebas;

    graphicObjects p;
    p.setFieldLimits(50,0,0,30);
    p.setDir(DIR_RIGHT);
    p.setSpeed(0.004);
    p.setPos(3,3);

    pruebas.append(p);

    p.setDir(DIR_DOWN);
    p.setSpeed(0.001);
    p.setPos(30,3);

    pruebas.append(p);

    p.setDir(DIR_UP);
    p.setSpeed(0.002);
    p.setPos(6,25);

    pruebas.append(p);

    p.setDir(DIR_RIGHT);
    p.setSpeed(0.003);
    p.setPos(8,4);

    pruebas.append(p);

    p.setDir(DIR_LEFT);
    p.setSpeed(0.006);
    p.setPos(40,10);

    pruebas.append(p);


    for(;;)
    {
        bg::clrscr();
        for(int i=0; i<pruebas.size(); i++)
        {
            pruebas[i].paint();
            pruebas[i].tic(300);
        }
        Sleep(300);
    }

































//    bg::gotoxy(0,40);

    return 0;
}
