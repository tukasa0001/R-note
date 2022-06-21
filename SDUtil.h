#ifndef SDUTIL_H
#define SDUTIL_H
enum SDDataType
{
    String = 0,
    Int
};
typedef struct
{
    char* key[28];
    enum SDDataType type;
    void* value[100];
} SettingData;

void SDInit(SettingData* data, char* key, enum SDDataType type, void* value);
void SDInitStr(SettingData* data, char* key, char* str);
void SDInitInt(SettingData* data, char* key, int* num);
SettingData* SDFindIndex(SettingData* data[], size_t size, char* key);
#endif