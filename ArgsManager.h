#ifndef ARGSMGR_H
#define ARGSMGR_H
#include <stdbool.h>
//構造体・列挙型など
typedef enum
{
    Create = 0
} Operation;

typedef struct
{
    Operation operation;
    char *tag;
} argument;
typedef struct
{
    char *name;
    bool (*onPropSelect)(argument*);
} PropertyData;


//プロトタイプ宣言
void initArgs(argument *args, int argc, char *argv[]);
bool CheckShortProperty(char *prop, argument *args);
bool CheckLongProperty(char *prop, argument *args);
bool CheckProperty(PropertyData *AllPropData, size_t length, char *prop, argument *args);

bool Prop_Wipe(argument *args);
#endif