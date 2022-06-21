#include <stdio.h>
#include "SDUtil.h"

SettingData* SDCreate(char* key, enum SDDataType type, void* value)
{
    SettingData data;
    data.key = key;
    data.type = type;
    data.value = value;
    return &data;
}