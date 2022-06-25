#ifndef ARGSMGR_H
#define ARGSMGR_H
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
    void (*onPropSelect)(argument*);
} PropertyData;


//プロトタイプ宣言
void initArgs(argument *args, int argc, char *argv[]);
void CheckShortProperty(char *prop);
void CheckLongProperty(char *prop);

void Prop_Wipe(argument *args);
#endif