#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
//enum
//構造体
typedef struct
{
    char folder_path[200];
    char extension[10];
} SettingsData;

void LoadSettings(SettingsData *settings);
void SaveSettings(SettingsData *settings);
#endif