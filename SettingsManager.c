#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "SettingsManager.h"
#include "advio.h"


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
            printf("\e[41mエラー: 設定ファイルが読み込めませんでした。\e[0m\n終了します\n");
            exit(1);
            return;
        }
        else
        {// ファイルが作れた場合
            fclose(fp);
            printf("設定ファイルを新規作成しました。\n設定ファイルの編集を行ってください。\n");
            EditSettings(settings, true);
            SaveSettings(settings);
            fopen_s(&fp, "settings.txt", "r");
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
        else if(strcmp(key, "EditorPath") == 0) targetVal = settings->EditorPath;
        else if(strcmp(key, "DeleteEmptyFiles") == 0)
        {
            if(sscanYesOrNo(val) == Invalid) targetVal = NULL;
            else targetVal = settings->DeleteEmptyFiles;
        }

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
    fprintf(fp, "EditorPath = %s\n", settings->EditorPath);
    fprintf(fp, "DeleteEmptyFiles = %s\n", settings->DeleteEmptyFiles);
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
    
    YesOrNo deleteEmptyFiles = sscanYesOrNo(settings->DeleteEmptyFiles);
    if(deleteEmptyFiles == Invalid) strcpy(settings->DeleteEmptyFiles, "TRUE");

    return doRewrite;
}

void EditSettings(SettingsData *settings, bool editAll)
{
    char *values[AllSettingsNum] = {
        settings->folder_path,
        settings->extension,
        settings->EditorPath,
        settings->DeleteEmptyFiles
    };
    char *messages[AllSettingsNum] = {
        "メモの保存先フォルダー",
        "メモの拡張子",
        "テキストエディターのパス",
        "空のメモを自動で削除する(yes/no)"
    };
    char *defaultValues[AllSettingsNum] = {
        ".\\",
        "txt",
        "notepad.exe",
        "yes"
    };
    bool noChanges = true;
    for(int i = 0; i < AllSettingsNum; i++)
    {
        char *val = values[i];
        char *msg = messages[i];

        if(*(val-1) != 1 || editAll)
        {
            if(noChanges && !editAll) printf("\e[31m未割当の設定が見つかりました。\e[0m\n");
            printf("デフォルト値: \"%s\"\n", defaultValues[i]);
            printf(msg);
            printf(" >");
            fgets(val, SDGetLength(val), stdin);
            if(strlen(val) <= 1) 
            {
                strcpy(val, defaultValues[i]);
                printf("入力がなかったため、デフォルト値\"%s\"を適用しました。\n", defaultValues[i]);
            }
            noChanges = false;
        }
    }

    if(!noChanges) SaveSettings(settings);
}

void InitSettings(SettingsData *settings)
{
    settings->length_FolderPath = FolderPathLen;
    settings->length_extension = ExtensionLen;
    settings->length_EditorPath = EditorPathLen;
    settings->length_DeleteEmptyFiles = DeleteEmptyFilesLen;
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