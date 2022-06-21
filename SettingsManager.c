#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SettingsManager.h"

SettingsData settings;

void LoadSettings()
{
    FILE* fp;
    errno_t er1, er2;
    er1 = fopen_s(fp, "settings.txt", "r");
    if(er1 != 0)
    {// ファイルが存在しないか開けない場合
        er2 = fopen_s(fp, "settings.txt", "w");
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
    *settings.path = "C:\\";
    *settings.extension = "txt";
}
void SaveSettings()
{
    FILE* fp;
    errno_t er1 = fopen_s(fp, "settings.txt", "w");
    if(er1 != 0)
    {
        printf("エラー: 設定ファイルを編集できませんでした。");
        return;
    }
}