#ifndef FILECTRL_H
#define FILECTRL_H
#include "SettingsManager.h"

//プロトタイプ宣言
void CreateAndOpenFile(char *tag, SettingsData *settings);
void getFileName(char *filename, long long unsigned int size, char *tag);
#endif