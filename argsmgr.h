#ifndef ARGSMGR_H
#define ARGSMGR_H
typedef enum
{
    Create = 0
} Operation;

typedef struct
{
    Operation operation;
    char* tag;
} argument;
#endif