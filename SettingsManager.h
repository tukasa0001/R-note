#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
//構造体
typedef struct
{
    char* path[160];
    char* extension[10];
} SettingsData;

void LoadSettings();
void initSettings();
#endif