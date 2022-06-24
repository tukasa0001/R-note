#include <stdio.h>
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
        //YES判定
        if(strcmp(str, "Yes") == 0 ||
            strcmp(str, "yes") == 0 ||
            strcmp(str, "YES") == 0 ||
            strcmp(str, "Y") == 0 ||
            strcmp(str, "y") == 0 ||
            strcmp(str, "True") == 0 ||
            strcmp(str, "true") == 0 ||
            strcmp(str, "TRUE") == 0 ||
            strcmp(str, "T") == 0 ||
            strcmp(str, "t") == 0
        ) return true;
        //NO判定
        if(strcmp(str, "No") == 0 ||
            strcmp(str, "no") == 0 ||
            strcmp(str, "NO") == 0 ||
            strcmp(str, "N") == 0 ||
            strcmp(str, "n") == 0 ||
            strcmp(str, "False") == 0 ||
            strcmp(str, "false") == 0 ||
            strcmp(str, "FALSE") == 0 ||
            strcmp(str, "F") == 0 ||
            strcmp(str, "f") == 0
        ) return false;
    }
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