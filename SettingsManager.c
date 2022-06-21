#include <stdio.h>
#include <stdlib.h>
#include "SettingsManager.h"

SettingsData settings;

void LoadSettings()
{
    FILE* fp;
    errno_t err = fopen_s(fp, "settings.txt", "r");
    if(err != 0)
    {// ファイルが存在しないか開けない場合
    }
}

void initSettings()
{
    *settings.path = "C:\\";
    *settings.extension = "txt";
}