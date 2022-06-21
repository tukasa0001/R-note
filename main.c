#include <stdio.h>
#include "ArgsManager.h"

argument args;
void main(int argc, char* argv[])
{
    initArgs(&args, argc, argv);

    printf("argument構造体の状態: \n");
    printf("    operationID: %d\n", (int)args.operation);
    printf("    tag: %s\n", args.tag);
}