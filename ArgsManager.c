#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArgsManager.h"

void initArgs(argument* args, int argc, char* argv[])
{
    bool isTagAssigned = false;

    for (int i = 1; i < argc; i++)
    {
        char* arg = argv[i];
        switch(*arg)
        {
            case '-':
                // プロパティを表す予定だが未実装
                printf("警告: プロパティは未実装です");
                break;
            default:
                if(!isTagAssigned)
                {// タグとして割りあてる
                    args->tag = arg;
                    isTagAssigned = true;
                }
                else
                {
                    printf("エラー: 不正な引数: %s\n何かキーを押して終了します", arg);
                    getchar();
                    exit(1);
                }
                break;
        }
    }
}