#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "SettingsManager.h"
#include "FileControl.h"
#include "advio.h"

extern SettingsData settings;
//関数名: CreateAndOpenFile
//戻り値: void
//char *tag: コマンドライン引数で指定されたタグ
char* CreateAndOpenFile(char *tag)
{
    char path[255];
    strcpy(path, settings.folder_path);
    static char filename[125];
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
            scanf_s("%s", settings.folder_path, SDGetIsRead(settings.folder_path));
            SaveSettings(&settings);
        }
        exit(1);
        return NULL;
    }
    fprintf(fp, "ファイル作成テスト(%s)", path);
    fclose(fp);

    ShellExecute(NULL, "open", settings.EditorPath, path, NULL, SW_RESTORE);
    return filename;
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

void RemoveEmptyFiles(char *excludeFilename)
{
    char searchPath[142];
    strcpy(searchPath, settings.folder_path);
    strcat(searchPath, "*.");
    strcat(searchPath, settings.extension);

    HANDLE fHandle;
    WIN32_FIND_DATA fd;
    fHandle = FindFirstFile(searchPath, &fd);
    if(fHandle == INVALID_HANDLE_VALUE) return;
    char removePath[255];
    do
    {
        if(fd.nFileSizeLow <= 0 && strcmp(fd.cFileName, excludeFilename) != 0)
        {
            strcpy(removePath, settings.folder_path);
            strcat(removePath, fd.cFileName);
            if(!DeleteFile(removePath))
            {
                printf("警告: 空のファイルファイル\"%s\"の削除に失敗しました。\n", fd.cFileName);
            }
        }
    } while (FindNextFile(fHandle, &fd));

    FindClose(fHandle);
}

void WipeAllFiles()
{
    char searchPath[142];
    strcpy(searchPath, settings.folder_path);
    strcat(searchPath, "*.");
    strcat(searchPath, settings.extension);

    HANDLE fHandle;
    WIN32_FIND_DATA fd;
    fHandle = FindFirstFile(searchPath, &fd);
    if(fHandle == INVALID_HANDLE_VALUE) return;
    char removePath[255];
    do
    {
        strcpy(removePath, settings.folder_path);
        strcat(removePath, fd.cFileName);
        if(!DeleteFile(removePath))
        {
            printf("警告: \"%s\"の削除に失敗しました。\n", fd.cFileName);
        }
        else
        {
            printf("削除: \"%s\"\n", fd.cFileName);
        }
    } while (FindNextFile(fHandle, &fd));

    FindClose(fHandle);
}