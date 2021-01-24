#ifndef STACK_H
#define STACK_H
#ifndef StackElement
#define StackElement int
#endif
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    StackElement* array;
    int64_t size;
    StackElement CANARY = rand();
    int64_t capacity;
} IronStack;

IronStack StackConstruct(int64_t size, int64_t capacity);
void Push(IronStack Stack, StackElement new_el);
StackElement Pop(IronStack Stack);
StackElement Top(IronStack Stack);
int64_t Size(IronStack Stack);
IronStack Reallocate(IronStack Stack, int64_t new_capacity);
void Check(IronStack Stack);

#endif STACK_H