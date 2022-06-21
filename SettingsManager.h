#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
//enum
//構造体
typedef struct
{

} SettingsData;

void LoadSettings(SettingsData *AllSettings, size_t size);
void InitSettings(SettingsData *AllSettings, size_t size);
void SaveSettings(SettingsData *AllSettings, size_t size);
#endif