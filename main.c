#include <stdio.h>
#include "argsmgr.h"

void main(int argc, char* argv[])
{
    argument* args = initArgs(argc, argv);

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args->operation);
    printf("    tag: %s\n", args->tag);
}