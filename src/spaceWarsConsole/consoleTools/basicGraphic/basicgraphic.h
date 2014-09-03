//Function definitions for console display manipulation
#ifndef BASICGRAPHIC_H
#define BASICGRAPHIC_H
#include <windows.h>

//basicGraphic colours defines
#define BG_DARK_BLUE    1
#define BG_DARK_GREEN   2
#define BG_DARK_CYAN    3
#define BG_DARK_RED     4
#define BG_DARK_PINK    5
#define BG_DARK_YELLOW  6
#define BG_DARK_WHITE   7
#define BG_DARK_GRAY    8
#define BG_BLUE         9
#define BG_GREEN        10
#define BG_CYAN         11
#define BG_RED          12
#define BG_PINK         13
#define BG_YELLOW       14
#define BG_WHITE        15

namespace bg
{

/// \brief  Put cursor into (x,y) coordinates on the console
void gotoxy(int x, int y);

/// \brief  Clear the console.
void clrscr();

/// \brief  Set the console pointer color.
/// \param[in]  color   Determine the choosen color.
///                     Use the defined macros for better understanding.
///                     There are also other colours that are not defined in macros, but you can check all the other accepted values.
void setColor(unsigned char color = BG_WHITE);

}
#endif // BASICGRAPHIC_H
