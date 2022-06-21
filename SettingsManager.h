#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
//enum
enum DataType
{
    String = 0,
    Int
};
//構造体
typedef struct
{
    char* path[160];
    char* extension[10];
} SettingsData;
typedef struct
{
    char* key[10];
    enum DataType type;
    void* value;
} SettingData;


void LoadSettings();
void initSettings();
void SaveSettings();
#endif