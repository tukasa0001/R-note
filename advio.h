#ifndef ADVIO_H
#define ADVIO_h

typedef enum
{
    Black = 0,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
} Color;
//プロトタイプ宣言
bool scanYesOrNo(char *msg);
void SetTextColor(Color color);
void SetBGColor(Color color);
#endif