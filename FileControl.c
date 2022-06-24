#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "SettingsManager.h"
#include "FileControl.h"
#include "advio.h"

//関数名: CreateFile
//戻り値: void
//char *tag: コマンドライン引数で指定されたタグ
void CreateFile(char *tag, SettingsData *settings)
{
    char path[284];
    strcpy(path, settings->folder_path);
    char filename[84];
    getFileName(filename, sizeof(filename) / sizeof(filename[0]), tag);
    strcat(path, filename);

    FILE *fp;
    errno_t en1;
    en1 = fopen_s(&fp, path, "w");
    if(en1 != 0)
    {
        printf("エラー: ファイルを作成できませんでした。(path: %s)\n", path);
        bool changePath = scanYesOrNo("保存先フォルダパスを変更しますか? >");
        if(changePath)
        {
            printf("メモの保存先フォルダー =>");
            scanf("%s", settings->folder_path);
            SaveSettings(settings);
        }
        return;
    }
    fprintf(fp, "ファイル作成テスト(%s)", path);
    fclose(fp);
}

//関数名: getFileName
//戻り値: void
//char *filename: ファイル名の格納先(注: サイズ30以上のchar配列のポインタとすること)
//long long unsigned int size: ファイル名の配列の大きさ
//char *tag: コマンドライン引数で指定されたタグ
void getFileName(char *filename, long long unsigned int size, char *tag)
{
    if(size < 30)
    {
        if(7 <= size) filename = "INVALID";
        return;
    }
    time_t now = time(NULL);
    char timestamp[20];
    // 2000.01.01-00.00.00
    strftime(timestamp, sizeof(timestamp), "%Y.%m.%d-%H.%M.%S", localtime(&now));

    if(tag != NULL && strlen(timestamp)+strlen(tag)+strlen("txt")+4 <= size)
    {
        snprintf(filename, size, "%s-[%s].%s", timestamp, tag, "txt");
    }
    else snprintf(filename, size, "%s.%s", timestamp, "txt");
}