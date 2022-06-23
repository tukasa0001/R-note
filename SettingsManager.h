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
    char isRead_FolderPath;
    char folder_path[200];
    char isRead_extension;
    char extension[10];
} SettingsData;

void LoadSettings(SettingsData *settings);
void SaveSettings(SettingsData *settings);
void FixSettings(SettingsData *settings);
void EditSettings(SettingsData *settings, bool editAll);
#endif