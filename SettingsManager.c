#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SettingsManager.h"


void LoadSettings(SettingsData *settings, size_t size)
{
    FILE *fp;
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
            fopen_s(&fp, "settings.txt", "r");
        }
    }
    //読み込み処理
    char line[128];
    int i = 0;
    while (fgets(line, 128, fp) != NULL)
    {
        printf(line);
        i++;
    }
    fclose(fp);
}

void InitSettings(SettingsData *settings, size_t size)
{

}

void SaveSettings(SettingsData *settings, size_t size)
{
    FILE *fp;
    errno_t er1 = fopen_s(&fp, "settings.txt", "w");
    if(er1 != 0)
    {
        printf("エラー: 設定ファイルを編集できませんでした。");
        return;
    }
    //書き込み処理
    fclose(fp);
}