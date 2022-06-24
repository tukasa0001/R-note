#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
#include <stdbool.h>
//enum
//構造体
#define AllSettingsNum 2
typedef struct
{
    char length_FolderPath;
    char isRead_FolderPath;
    char folder_path[200];
    
    char length_extension;
    char isRead_extension;
    char extension[10];
} SettingsData;

void LoadSettings(SettingsData *settings);
void SaveSettings(SettingsData *settings);
bool FixSettings(SettingsData *settings, bool DoNotRewrite);
void EditSettings(SettingsData *settings, bool editAll);
#endif