#include <stdio.h>
#include <string.h>
#include "ArgsManager.h"
#include "FileControl.h"
#include "SettingsManager.h"

argument args;
SettingsData settings;

void main(int argc, char *argv[])
{
    initArgs(&args, argc, argv);
    initSettings();

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args.operation);
    printf("    tag: %s\n", args.tag);

    CreateFile(args.tag);
}

void initSettings()
{
    strcpy(settings.folder_path, "C:\\note\\");
    strcpy(settings.extension, "txt");
}