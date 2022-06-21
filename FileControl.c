#include <stdio.h>
#include <time.h>
#include <string.h>
#include "FileControl.h";

void CreateFile(char* tag)
{
    char* filename = getFileName(tag);
    FILE* file;
    file = fopen(filename, "w+");
    fprintf(file, "ファイル作成テスト(%s)", filename);
    fclose(file);
}

char* getFileName(char* tag)
{
    char* filename[32];
    time_t now = time(NULL);
    // 2000.01.01-00.00.00
    strftime(filename, sizeof(filename), "%Y.%m.%d-%H.%M.%S", localtime(&now));
    strcat(filename, ".txt");
    return filename;
}