#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArgsManager.h"

//関数名: initArgs
//戻り値: void
//argument *args: 書き込み先の構造体
//int argc: コマンドライン引数の数
//char *argv[]: コマンドライン引数
void initArgs(argument *args, int argc, char *argv[])
{
    bool isTagAssigned = false;

    for (int i = 1; i < argc; i++)
    {
        char *arg = argv[i];
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
static PropertyData ShortPropertyData[] = {
    {"w", Prop_Wipe}
};
static PropertyData LongPropertyData[] = {
    {"wipe", Prop_Wipe}
};

bool CheckShortProperty(char *prop, argument *args)
{
    size_t length = sizeof(ShortPropertyData) / sizeof(PropertyData);
    return CheckProperty(ShortPropertyData, length, prop, args);
}
bool CheckLongProperty(char *prop, argument *args)
{
    size_t length = sizeof(LongPropertyData) / sizeof(PropertyData);
    return CheckProperty(LongPropertyData, length, prop, args);
}
bool CheckProperty(PropertyData *AllPropData, size_t length, char *prop, argument *args)
{
    for(int i = 0; i < length; i++)
    {
        PropertyData propData = AllPropData[i];
        if(strcmp(propData.name, prop) == 0)
        {
            propData.onPropSelect(args);
            return true;
        }
    }
    return false;
}

void Prop_Wipe(argument *args)
{
}