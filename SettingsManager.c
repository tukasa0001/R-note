#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SettingsManager.h"
#include "SDUtil.h"


void LoadSettings(SettingData* AllSettings, size_t size)
{
    FILE* fp;
    errno_t er1, er2;
    er1 = fopen_s(&fp, "settings.txt", "r");
    if(er1 != 0)
    {// ファイルが存在しないか開けない場合
        er2 = fopen_s(&fp, "settings.txt", "w");
        if(er2 != 0)
        {// ファイルが作れない場合
            printf("エラー: 設定ファイルが読み込めませんでした。\n初期設定のまま続行します。\n");
            return;
        }
        else
        {// ファイルが作れた場合
            printf("設定ファイルを生成しました。\n");
            fclose(fp);
            SaveSettings(AllSettings, size);
            fopen_s(&fp, "settings.txt", "r");
        }
    }
    //読み込み処理
    char line[128];
    int i = 0;
    while (fgets(line, 128, fp) != NULL)
    {
        printf(line);
        char key[28];
        enum SDDataType type;
        sscanf(line, "[type-%d]%s = %*s", &type, key);

        SettingData* stg = SDFindIndex(AllSettings, size, key);
        if(stg == NULL)
        {
            i++;
            continue;
        }
        switch (type)
        {
            case String:
                printf("%s はStringです\n", stg->key);
                sscanf(line, "[type-%*d] %*s = %s", stg->value);
                break;
            case Int:
                printf("%s はIntです\n", stg->key);
                sscanf(line, "[type-%*d] %*s = %d", stg->value);
                break;
            default:
                printf("エラー: 不明なDataType (%d)", type);
                break;
        }
        i++;
    }
    fclose(fp);
}

void InitSettings(SettingData* AllSettings, size_t size)
{
    SDInitStr(&AllSettings[0], "FilePath", "C:\\notes\\");
    SDInitStr(&AllSettings[1], "Extension", "txt");
}

void SaveSettings(SettingData* AllSettings, size_t size)
{
    FILE* fp;
    errno_t er1 = fopen_s(&fp, "settings.txt", "w");
    if(er1 != 0)
    {
        printf("エラー: 設定ファイルを編集できませんでした。");
        return;
    }
    //書き込み処理
    size_t length = size / sizeof(AllSettings[0]);
    for(int i = 0; i < length; i++)
    {
        switch (AllSettings[i].type)
        {
            case String:
                fprintf(fp, "[type-%d] %s = %s", AllSettings[i].type, AllSettings[i].key, (char*)AllSettings[i].value);
                break;
            case Int:
                fprintf(fp, "[type-%d] %s = %d",AllSettings[i].type, AllSettings[i].key, (int*)AllSettings[i].value);
                break;
            default:
                printf("エラー: 不正なDataType(%d)", AllSettings[i].type);
                break;
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}