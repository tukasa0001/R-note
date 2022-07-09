#include <stdio.h>
#include <string.h>
#include "ArgsManager.h"
#include "FileControl.h"
#include "SettingsManager.h"
#include "advio.h"
#define debug

argument args;
SettingsData settings;

void main(int argc, char *argv[])
{
    initArgs(&args, argc, argv);

    InitSettings(&settings);
    LoadSettings(&settings);

#ifdef debug
    printf("\n\n=====DEBUG=====\n");
    printf("SettingsData構造体の状態: \n");
    printf("    Folder_Path: %s\n", settings.folder_path);
    printf("    extension: %s\n", settings.extension);

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args.operation);
    printf("    tag: %s\n", args.tag);
    printf("===============\n\n");
#endif

    switch (args.operation)
    {
        case Create: {
            char *filename = CreateAndOpenFile(args.tag);
            if(CheckYesOrNo(settings.DeleteEmptyFiles) == Yes)
                RemoveEmptyFiles(filename);
            break;
        }

        case Wipe: {
            break;
        }

        default:
            printf("エラー: 処理モードが不正です");
            break;
    }
}