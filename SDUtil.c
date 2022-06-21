#include <stdio.h>
#include "SDUtil.h"

void SDInit(SettingData* data, char* key, enum SDDataType type, void* value)
{
    data->key = key;
    data->type = type;
    data->value = value;
}
void SDInitStr(SettingData* data, char* key, char* str)
{
    data->key = key;
    data->type = String;
    data->value = str;
}
void SDInitInt(SettingData* data, char* key, int* num)
{
    data->key = key;
    data->type = Int;
    data->value = num;
}