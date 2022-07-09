#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "advio.h"

bool scanYesOrNo(char *msg)
{
    char str[10];
    while(true)
    {
        printf(msg);
        scanf_s("%s", str, 10);
        switch (CheckYesOrNo(str))
        {
            case Yes: return true;
            case No: return false;
            case Invalid:
            default:
                break;
        }
    }
}

YesOrNo CheckYesOrNo(char *input)
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
//toShift: シフトする文字数。1の場合、"1234"=>"234"のように動きます。
char* strLeftShift(char *input, int toShift)
{
    int length = strlen(input);
    char *str;
    str = (char*)malloc(sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        str[i] = input[i+toShift];
    }
    return str;
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