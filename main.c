#include <stdio.h>
#include "ArgsManager.h"
#include "FileControl.h"
#include "SettingsManager.h"
#include "SDUtil.h"

argument args;
SettingData AllSettings[2];

void main(int argc, char *argv[])
{
    initArgs(&args, argc, argv);

    InitSettings(AllSettings, sizeof(AllSettings));
    LoadSettings(AllSettings, sizeof(AllSettings));

    printf("設定ファイルの状態\n");
    printf("    保存先dir: %s\n", (char*)SDFindIndex(AllSettings, sizeof(AllSettings), "FilePath")->value);
    printf("    拡張子: %s\n", (char*)SDFindIndex(AllSettings, sizeof(AllSettings), "Extension")->value);

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args.operation);
    printf("    tag: %s\n", args.tag);

    CreateFile(args.tag);
}