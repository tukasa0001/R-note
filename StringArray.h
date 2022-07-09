#ifndef STRARR
#define STRARR
#include <stdbool.h>
typedef struct
{
    int size;
    int used;
    char *string;
    char **stringPtr;
    int length;
    int ptrSize;
} StringArray;

StringArray* StringArray_init(int size);
bool ExpandStr(StringArray *arr, int toAdd);
bool ExpandPtr(StringArray *arr, int toAdd);
bool Add(StringArray *arr, char *str);
#endif