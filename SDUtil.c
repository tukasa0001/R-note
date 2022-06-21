#include <stdio.h>
#include <string.h>
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
SettingData* SDFindIndex(SettingData* data[], size_t size, char* key)
{
    size_t length = size / sizeof(*(data[0]));
    for (size_t i = 0; i < size; i++)
    {
        if(strcmp(data[i]->key, key)) return &data[i];
    }
    return NULL;
}