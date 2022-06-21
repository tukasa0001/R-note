#include <stdio.h>
#include <time.h>
#include <string.h>
#include "FileControl.h";

//関数名: CreateFile
//戻り値: void
//char* tag: コマンドライン引数で指定されたタグ
void CreateFile(char* tag)
{
    char* filename = getFileName(tag);
    FILE* fp;
    errno_t en1;
    en1 = fopen_s(&fp, filename, "w");
    if(en1 != 0) return;
    fprintf(fp, "ファイル作成テスト(%s)", filename);
    fclose(fp);
}

//関数名: getFileName
//戻り値: 作るファイル名
//char* tag: コマンドライン引数で指定されたタグ
char* getFileName(char* tag)
{
    char* filename[32];
    time_t now = time(NULL);
    // 2000.01.01-00.00.00
    strftime(filename, sizeof(filename), "%Y.%m.%d-%H.%M.%S", localtime(&now));
    strcat(filename, ".txt");
    return filename;
}