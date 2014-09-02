#include "graphicchar.h"


graphicChar::graphicChar()
{
    graphicChar(point(),'-', BG_GREEN);
}

graphicChar::graphicChar(point pos, unsigned char ch, unsigned char colour)
{
    _pos=pos;
    _char=ch;
    _colour=colour;
}

int graphicChar::paint(point offset)
{
    point p = offset + _pos;
    bg::gotoxy(p.xInt(),p.yInt());
    bg::setColor(_colour);
    std::cout<< _char;

    return 0;
}
