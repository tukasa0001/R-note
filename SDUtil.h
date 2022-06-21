#ifndef SDUTIL_H
#define SDUTIL_H
enum SDDataType
{
    String = 0,
    Int
};
typedef struct
{
    char* key[10];
    enum SDDataType type;
    void* value;
} SettingData;
#endif