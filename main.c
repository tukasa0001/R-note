#include <stdio.h>
#include <string.h>
#include "ArgsManager.h"
#include "FileControl.h"
#include "SettingsManager.h"

argument args;
SettingsData settings;

void initSettings();

void main(int argc, char *argv[])
{
    initArgs(&args, argc, argv);
    initSettings();

    LoadSettings(&settings);

    printf("SettingsData構造体の状態: \n");
    printf("    Folder_Path: %s\n", settings.folder_path);
    printf("    extension: %s\n", settings.extension);

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