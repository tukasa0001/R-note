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

//プロトタイプ宣言
void initArgs(argument *args, int argc, char *argv[]);
#endif