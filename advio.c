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
        if(strcmp(str, "Yes") +
            strcmp(str, "yes") +
            strcmp(str, "YES") +
            strcmp(str, "Y") +
            strcmp(str, "y") +
            strcmp(str, "True") +
            strcmp(str, "true") +
            strcmp(str, "TRUE") +
            strcmp(str, "T") +
            strcmp(str, "t")
            == 1
        ) return true;
        //NO判定
        if(strcmp(str, "No") +
            strcmp(str, "no") +
            strcmp(str, "NO") +
            strcmp(str, "N") +
            strcmp(str, "n") +
            strcmp(str, "False") +
            strcmp(str, "false") +
            strcmp(str, "FALSE") +
            strcmp(str, "F") +
            strcmp(str, "f")
            == 1
        ) return false;
    }
}