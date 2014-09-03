#ifndef GRAPHICCHAR_H
#define GRAPHICCHAR_H
#include "point.h"
#include "consoleTools/basicGraphic/basicgraphic.h"
#include <iostream>
class graphicChar
{
private:
    // char relative position
    point _pos;

    // char to paint
    unsigned char _char;

    // char colour
    unsigned char _colour;

public:
    /// \brief Initialize the object with empty parameters
    graphicChar();

    /// \brief Initialize the object, but giving it specific parameters.
    graphicChar(point pos, unsigned char ch, unsigned char colour=BG_WHITE);

    /// \brief Paint itself with a relative offset.
    ///
    /// \param[in] offset painting offset
    ///  \return 0 if painting process end Ok. errorCode if an error occur.
    int paint(point offset);

};

#endif // GRAPHICCHAR_H
