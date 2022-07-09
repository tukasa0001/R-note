#include "StringArray.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

StringArray* StringArray_init(int size)
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
bool Add(StringArray *arr, char *str)
{
    bool err_str = false, err_ptr = false;
    int strLength = strlen(str);
    if(arr->size - arr->used < strLength) err_str = !ExpandStr(arr, strLength*1.5);
    if(arr->ptrSize - arr->length < 1) err_ptr = !ExpandPtr(arr, 5);

    if(err_str || err_ptr) return false;

    strcpy((arr->string + arr->used), str);
    strcpy((arr->string + arr->used + sizeof(char)), "\0");
    arr->stringPtr[arr->length+1] = (arr->string + arr->used);
    arr->used += strLength + 1;
    arr->length++;
}