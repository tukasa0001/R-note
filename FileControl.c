#include <stdio.h>
#include <time.h>
#include <string.h>
#include "FileControl.h"

//関数名: CreateFile
//戻り値: void
//char* tag: コマンドライン引数で指定されたタグ
void CreateFile(char* tag)
{
    char filename[30];
    getFileName(filename, sizeof(filename), tag);
    FILE* fp;
    errno_t en1;
    en1 = fopen_s(&fp, filename, "w");
    if(en1 != 0) return;
    fprintf(fp, "ファイル作成テスト(%s)", filename);
    fclose(fp);
}

//関数名: getFileName
//戻り値: void
//char* filename: ファイル名の格納先(注: サイズ30以上のchar配列のポインタとすること)
//int size: ファイル名の配列の大きさ
//char* tag: コマンドライン引数で指定されたタグ
void getFileName(char* filename, int size, char* tag)
{
    if(size < 30)
    {
        if(7 <= size) filename = "INVALID";
        return;
    }
    time_t now = time(NULL);
    // 2000.01.01-00.00.00
    strftime(filename, size, "%Y.%m.%d-%H.%M.%S", localtime(&now));
    strcat(filename, ".txt");
    printf("filename: %s", filename);
}