#include <stdio.h>
#include <stdbool.h>
#include "argsmgr.h"

argument* initArgs(int argc, char* argv[])
{
    argument* args;
    int i = 0;
    bool isTagAssigned = false;

    args->operation = Create;
    args->tag = NULL;
    for (int i = 0; i < argc; i++)
    {
        char* arg = argv[i];
        printf("Switch文直前です。私が戻らなかったら通報してください。");
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
                }
                else
                {
                    printf("エラー: 不正な引数: %s\n何かキーを押して終了します", arg);
                    getchar();
                }
                break;
        }
        printf("無事戻ってこれました！");
    }

    return args;
}