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


void LoadSettings();
void initSettings();
void SaveSettings();
#endif