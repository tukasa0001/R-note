#include <stdio.h>
#include <string.h>
#include "ArgsManager.h"
#include "FileControl.h"
#include "SettingsManager.h"
#define debug

argument args;
SettingsData settings;

void main(int argc, char *argv[])
{
    initArgs(&args, argc, argv);

    InitSettings(&settings);
    LoadSettings(&settings);

#ifdef debug
    printf("SettingsData構造体の状態: \n");
    printf("    Folder_Path: %s\n", settings.folder_path);
    printf("    extension: %s\n", settings.extension);

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args.operation);
    printf("    tag: %s\n", args.tag);
#endif

    char *filename = CreateAndOpenFile(args.tag);
}