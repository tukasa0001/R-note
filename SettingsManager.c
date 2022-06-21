#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SettingsManager.h"
#include "SDUtil.h"

SettingData AllSettings[2];

void LoadSettings()
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
            // セーブ処理
        }
    }
    //読み込み処理

}

void initSettings()
{
    SDInitStr(&AllSettings[0], "FilePath", "C:\\notes\\");
    SDInitStr(&AllSettings[1], "Extension", "txt");
}
void SaveSettings()
{
    FILE* fp;
    errno_t er1 = fopen_s(&fp, "settings.txt", "w");
    if(er1 != 0)
    {
        printf("エラー: 設定ファイルを編集できませんでした。");
        return;
    }
    //書き込み処理
    size_t size = sizeof(AllSettings);
    for(int i = 0; i < size; i++)
    {
        if(i != 0) fprintf(fp, "\n");
        switch (AllSettings[i].type)
        {
            case String:
                fprintf(fp, "[type-%d]%s = %s", AllSettings[i].type, AllSettings[i].key, (char*)AllSettings[i].value);
                break;
            case Int:
                fprintf(fp, "[type-%d]%s = %d",AllSettings[i].type, AllSettings[i].key, (int*)AllSettings[i].value);
                break;
            default:
                printf("エラー: 不正なDataType(%d)", AllSettings[i].type);
                break;
        }
    }
}