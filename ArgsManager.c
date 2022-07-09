#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArgsManager.h"
#include "advio.h"

//関数名: initArgs
//戻り値: void
//argument *args: 書き込み先の構造体
//int argc: コマンドライン引数の数
//char *argv[]: コマンドライン引数
void initArgs(argument *args, int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        char *arg = argv[i];
        bool isError;
        switch(*arg)
        {
            case '-':
                if(arg[1] == 1)
                {
                    char *str = strLeftShift(arg, 2); //"--prop" => "prop"
                    isError = !CheckLongProperty(str, args);
                } else {
                    char *str = strLeftShift(arg, 1); //"-p" => "p"
                    isError = !CheckShortProperty(str, args);
                }
                break;
            default:
                if(args->tag == NULL)
                {// タグとして割りあてる
                    args->tag = arg;
                }
                else isError = true;
                break;
        }
        if(isError)
        {
            printf("エラー: 不正な引数: %s\n何かキーを押して終了します", arg);
            getchar();
            exit(1);
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
            return propData.onPropSelect(args);
        }
    }
    return false;
}

bool Prop_Wipe(argument *args)
{
    if(args->operation == Create && args->tag == NULL)
    {
        args->operation = Wipe;
        return true;
    }
    else
    {
        return false;
    }
}