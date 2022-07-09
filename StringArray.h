#ifndef STRARR
#define STRARR

typedef struct
{
    int size;
    int used;
    char *string;
    char **stringPtr;
    int length;
    int ptrSize;
} StringArray;
#endif