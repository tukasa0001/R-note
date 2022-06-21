#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
#include "SDUtil.h"
//enum
//構造体


void LoadSettings(SettingData *AllSettings, size_t size);
void InitSettings(SettingData *AllSettings, size_t size);
void SaveSettings(SettingData *AllSettings, size_t size);
#endif