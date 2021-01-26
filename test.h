#ifndef TEST_H
#define TEST_H

#include <stdint.h>
#include "stack.h"

bool Test_StackConstruct(int64_t size, int64_t capacity);
bool Test_Push(IronStack* Stack, StackElement new_el);
bool Test_Pop(IronStack* Stack);
bool Test_Top(IronStack* Stack);
bool Test_Size(IronStack* Stack);
bool Test_Reallocate(IronStack* Stack, int64_t new_capacity);
bool Test_Check(IronStack* Stack);

#endif //TEST_H
