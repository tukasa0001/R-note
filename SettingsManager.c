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
            EditSettings(settings, true);
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
        sscanf_s(line, "%s = %s", key,20, val,100);

        char *targetVal = NULL;
        if(strcmp(key, "Folder_Path") == 0) targetVal = settings->folder_path;
        else if(strcmp(key, "Extension") == 0) targetVal = settings->extension;

        if(targetVal != NULL)
        {
            strcpy(targetVal, val);
            *(targetVal - 1) = 1;
        }
        i++;
    }
    fclose(fp);
    FixSettings(settings, false);
    EditSettings(settings, false);
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
    FixSettings(settings, true);
    //書き込み処理
    fprintf(fp, "Folder_Path = %s\n", settings->folder_path);
    fprintf(fp, "Extension = %s\n", settings->extension);
    fclose(fp);
}

bool FixSettings(SettingsData *settings, bool DoNotRewrite)
{
    bool doRewrite = false;
    // Folder_Pathの最後の文字が"\"でない場合に"\"を付け加える
    char LastOfFolderPath = settings->folder_path[strlen(settings->folder_path) - 1];
    if(LastOfFolderPath != '\\')
    {
        strcat(settings->folder_path, "\\");
        doRewrite = true;
    }

    if(!DoNotRewrite && doRewrite)
    {
        SaveSettings(settings);
    }

    return doRewrite;
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
    bool noChanges = true;
    for(int i = 0; i < AllSettingsNum; i++)
    {
        char *val = values[i];
        char *msg = messages[i];

        if(*(val-1) != 1 || editAll)
        {
            printf(msg);
            scanf_s("%s", val, SDGetLength(val));
            noChanges = false;
        }
    }

    if(!noChanges) SaveSettings(settings);
}

void InitSettings(SettingsData *settings)
{
    settings->length_FolderPath = FolderPathLen;
    settings->length_extension = ExtensionLen;
}


bool SDGetIsRead(char *target)
{
    if(*(target - 1) == 1) return true;
    else return false;
}

unsigned char SDGetLength(char* target)
{
    return *(unsigned char*)(target - 2);
}