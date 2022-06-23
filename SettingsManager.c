#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "SettingsManager.h"


void LoadSettings(SettingsData *settings)
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
            fclose(fp);
            SaveSettings(settings);
            fopen_s(&fp, "settings.txt", "r");
            printf("設定ファイルを生成しました。\n");
        }
    }
    //読み込み処理
    char line[128];
    int i = 0;
    while (fgets(line, 128, fp) != NULL)
    {
        printf(line);

        char key[20], val[100];
        sscanf(line, "%s = %s", key, val);

        if(strcmp(key, "Folder_Path") == 0) strcpy(settings->folder_path, val);
        else if(strcmp(key, "Extension") == 0) strcpy(settings->extension, val);
        i++;
    }
    fclose(fp);
}

void SaveSettings(SettingsData *settings)
{
    FILE *fp;
    errno_t er1 = fopen_s(&fp, "settings.txt", "w");
    if(er1 != 0)
    {
        printf("エラー: 設定ファイルを編集できませんでした。\n");
        return;
    }
    FixSettings(settings);
    //書き込み処理
    fprintf(fp, "Folder_Path = %s\n", settings->folder_path);
    fprintf(fp, "Extension = %s\n", settings->extension);
    fclose(fp);
}

void FixSettings(SettingsData *settings)
{
    // Folder_Pathの最後の文字が"\"でない場合に"\"を付け加える
    //if(strcmp(strrchr(settings->folder_path, "\\"), "\0") != 0) strcat(settings->folder_path, "\\");
}

void EditSettings(SettingsData *settings, bool editAll)
{
    char *values[AllSettingsNum] = {
        settings->folder_path,
        settings->extension
    };
    char *messages[AllSettingsNum] = {
        "メモの保存先フォルダー",
        "メモの拡張子"
    };

    for(int i = 0; i < AllSettingsNum; i++)
    {
        char *val = values[i];
        char *msg = messages[i];
    }
}