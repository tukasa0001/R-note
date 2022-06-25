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
typedef enum
{
    Invalid = -1,
    No = 0,
    Yes = 1
} YesOrNo;
//プロトタイプ宣言
bool scanYesOrNo(char *msg);
YesOrNo sscanYesOrNo(char *input);
void ADVSetTextColor(Color color);
void SetBGColor(Color color);
void ResetColor();
#endif