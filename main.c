#include <stdio.h>
#include <string.h>
#include "ArgsManager.h"
#include "FileControl.h"
#include "SettingsManager.h"
#include "advio.h"

argument args;
SettingsData settings;

void main(int argc, char *argv[])
{
    initArgs(&args, argc, argv);

    InitSettings(&settings);
    LoadSettings(&settings);

    switch (args.operation)
    {
        case Create: {
            char *filename = CreateAndOpenFile(args.tag);
            if(CheckYesOrNo(settings.DeleteEmptyFiles) == Yes)
                RemoveEmptyFiles(filename);
            break;
        }

        case Wipe: {
            ADVSetTextColor(Yellow);
            printf("警告: この処理によって全てのメモが削除されます。\n");
            ResetColor();
            if(scanYesOrNo("続行しますか? [yes|no] >"))
            {
                WipeAllFiles();
                printf("\n削除が完了しました。何かキーを押すと終了します。\n");
                getchar();
            }
            else
            {
                printf("削除はキャンセルされました。何かキーを押すと終了します。\n");
                getchar();
            }
            break;
        }

        default:
            printf("エラー: 処理モードが不正です");
            break;
    }
}