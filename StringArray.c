#include "StringArray.h"
#include <stdlib.h>
#include <stdbool.h>

StringArray* Init(int size)
{
    StringArray *arr = malloc(sizeof(StringArray));
    arr->size = size;
    arr->string = malloc(sizeof(char) * size);
    arr->ptrSize = 10;
    arr->stringPtr = malloc(sizeof(char*) * 10);
}

bool ExpandStr(StringArray *arr, int toAdd)
{
    char *newPtr = realloc(arr->string, sizeof(char) * (arr->size + toAdd));
    if(newPtr == NULL) return false;
    arr->size += toAdd;
    arr->string = newPtr;
    return true;
}
bool ExpandPtr(StringArray *arr, int toAdd)
{
    char **newPtr = realloc(arr->stringPtr, sizeof(char*) * (arr->ptrSize + toAdd));
    if(newPtr == NULL) return false;
    arr->ptrSize += toAdd;
    arr->stringPtr = newPtr;
    return true;
}