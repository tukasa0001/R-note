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
    char *dir = (char*)SDFindIndex(AllSettings, sizeof(AllSettings), "FilePath")->value;
    char *ext = (char*)SDFindIndex(AllSettings, sizeof(AllSettings), "Extension")->value;
    printf("    保存先dir: %s(%p)\n", dir, dir);
    printf("    拡張子: %s(%p)\n", ext, ext);

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args.operation);
    printf("    tag: %s\n", args.tag);

    CreateFile(args.tag);
}