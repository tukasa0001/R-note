#ifndef SETTINGSMGR_H
#define SETTINGSMGR_H
//include
#include <stdio.h>
#include <stdbool.h>
//enum
//構造体
#define AllSettingsNum 4
typedef struct
{
    #define FolderPathLen 130
    unsigned char length_FolderPath;
    char isRead_FolderPath;
    char folder_path[FolderPathLen];

    #define ExtensionLen 10
    unsigned char length_extension;
    char isRead_extension;
    char extension[ExtensionLen];

    #define EditorPathLen 255
    unsigned char length_EditorPath;
    char isRead_EditorPath;
    char EditorPath[EditorPathLen];

    #define DeleteEmptyFilesLen 10
    unsigned char length_DeleteEmptyFiles;
    char isRead_DeleteEmptyFiles;
    char DeleteEmptyFiles[DeleteEmptyFilesLen];
} SettingsData;

void InitSettings(SettingsData *settings);
void LoadSettings(SettingsData *settings);
void SaveSettings(SettingsData *settings);
bool FixSettings(SettingsData *settings, bool DoNotRewrite);
void EditSettings(SettingsData *settings, bool editAll);

bool SDGetIsRead(char *target);
unsigned char SDGetLength(char* target);
#endif