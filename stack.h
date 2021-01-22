#ifndef StackElement
#define StackElement int
#endif
 
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    StackElement* array;
    long long size;
    StackElement CANARY = rand();
    long long capacity;
} IronStack;

 IronStack StackConstuct(long long size, long long capacity);
void Push(IronStack Stack, StackElement new_el);
StackElement Pop(IronStack Stack);
StackElement Top(IronStack Stack);
long long Size(IronStack Stack);
IronStack Reallocate(IronStack Stack, long long new_capacity);
void Check(IronStack Stack);
