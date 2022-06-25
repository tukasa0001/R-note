#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "advio.h"

static YesOrNo _CheckYesOrNo(char *input);
bool scanYesOrNo(char *msg)
{
    char str[10];
    while(true)
    {
        printf(msg);
        scanf_s("%s", str, 10);
        switch (_CheckYesOrNo(str))
        {
            case Yes: return true;
            case No: return false;
            case Invalid:
            default:
                break;
        }
    }
}

static YesOrNo _CheckYesOrNo(char *input)
{
    //YES判定
    if(strcmp(input, "Yes") == 0 ||
        strcmp(input, "yes") == 0 ||
        strcmp(input, "YES") == 0 ||
        strcmp(input, "Y") == 0 ||
        strcmp(input, "y") == 0 ||
        strcmp(input, "True") == 0 ||
        strcmp(input, "true") == 0 ||
        strcmp(input, "TRUE") == 0 ||
        strcmp(input, "T") == 0 ||
        strcmp(input, "t") == 0
    ) return Yes;
    //NO判定
    if(strcmp(input, "No") == 0 ||
        strcmp(input, "no") == 0 ||
        strcmp(input, "NO") == 0 ||
        strcmp(input, "N") == 0 ||
        strcmp(input, "n") == 0 ||
        strcmp(input, "False") == 0 ||
        strcmp(input, "false") == 0 ||
        strcmp(input, "FALSE") == 0 ||
        strcmp(input, "F") == 0 ||
        strcmp(input, "f") == 0
    ) return No;

    return Invalid;
}

void ADVSetTextColor(Color color)
{
    printf("\e[3%dm", color);
}
void SetBGColor(Color color)
{
    printf("\e[4%dm", color);
}
void ResetColor()
{
    printf("\e[0m");
}