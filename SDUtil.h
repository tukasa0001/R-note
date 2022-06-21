#ifndef SDUTIL_H
#define SDUTIL_H
typedef struct
{
    char* key[10];
    enum DataType type;
    void* value;
} SettingData;
#endif