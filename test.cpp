#include "test.h"

bool Test_StackConstruct(int64_t size, int64_t capacity) {
    IronStack Stack = StackConstruct(size, capacity);
    return (Stack.capacity == capacity && Stack.size == size && Test_Check(Stack));
}

bool Test_Push(IronStack& Stack, StackElement new_el) {
    Push(Stack, new_el);
    return (Stack.array[Stack.size] == new_el && Test_Check(Stack));
}

bool Test_Pop(IronStack& Stack) {
    StackElement old_el = Pop(Stack);
    return (old_el == Stack.array[Stack.size + 1] && Test_Check(Stack));
}

bool Test_Top(IronStack& Stack) {
    StackElement old_el = Top(Stack);
    return (old_el == Stack.array[Stack.size] && Test_Check(Stack));
}

bool Test_Size(IronStack& Stack) {
    int64_t old_size = Size(Stack);
    return (old_size == Stack.size);
}

bool Test_Reallocate(IronStack& Stack, int64_t new_capacity) {
    IronStack new_stack = Reallocate(Stack, new_capacity);
    return (new_stack.capacity == new_capacity && Test_Check(new_stack));
}

bool Test_Check(IronStack& Stack) {
    return (Stack.array[0] == Stack.CANARY && Stack.array[Stack.capacity + 1] == Stack.CANARY);
}
