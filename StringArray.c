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
    arr->size += toAdd;
    arr->string = realloc(arr->string, sizeof(char) * arr->size);
}
bool ExpandPtr(StringArray *arr, int toAdd)
{
    arr->ptrSize += toAdd;
    arr->stringPtr = realloc(arr->stringPtr, sizeof(char*) * arr->ptrSize);
}