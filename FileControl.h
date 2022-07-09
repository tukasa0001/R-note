#ifndef FILECTRL_H
#define FILECTRL_H
#include "SettingsManager.h"

//プロトタイプ宣言
char* CreateAndOpenFile(char *tag);
void getFileName(char *filename, long long unsigned int size, char *tag);
void RemoveEmptyFiles(char *excludeFilename);
void WipeAllFiles();
char* SelectFile(char *tag);
char* GetAllFiles();
#endif