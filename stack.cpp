#include "stack.h"

const int MULTIPLIER = 2;
const int N_CANARY = 2;

/**
* \brief Конструктор
* \detail Выставляет начальные значения для стека
* \param [in] size Размер стека
* \param [in] capacity Вместимость стека без учёта наличия канареек
* \throw Если невозможно выделить память
* \return Стек
*/

//uint64_t hashing (IronStack& Stack) {
//    uint64_t hash = 10;
//    for (int64_t i = 0; i < Size(Stack) - 1; ++i) {
//        hash += (i + 1) * Stack.begin[i] + 10;
//    }
//    return hash;
//}

IronStack StackConstruct(int64_t size, int64_t capacity) {
    IronStack Stack;
    Stack.capacity = capacity;
    Stack.array = (StackElement*) calloc(capacity + N_CANARY, sizeof(StackElement));
    if (Stack.array == NULL)
    {
        perror("Cannot allocate memory for stack.");
    }
    Stack.begin = Stack.array + 1;
    Stack.size = size;
//    Stack.hash = hashing(Stack);
    *Stack.array = Stack.CANARY;
    Stack.begin[Stack.capacity] = Stack.CANARY;
    return Stack;
}

void Push(IronStack& Stack, StackElement new_el) {
//    uint64_t old_hash = Stack.hash;
    if (Stack.size + 1 > Stack.capacity) {
        IronStack NewStack = Reallocate(Stack, MULTIPLIER * Stack.capacity);
    }

    Stack.begin[Size(Stack)] = new_el;
    ++Stack.size;
//    if (hashing(Stack) != old_hash + Stack.size * new_el + 10)
//        perror("The data in the stack is invalid");
    Check(Stack);
}

StackElement Pop(IronStack& Stack) {
    StackElement old_el = Stack.begin[Size(Stack) - 1];
    --Stack.size;
    Check(Stack);
    return old_el;
}

StackElement Top(IronStack& Stack) {
    Check(Stack);
    return Stack.begin[Size(Stack) - 1];
}

int64_t Size(IronStack& Stack) {
    Check(Stack);
    return Stack.size;
}

IronStack Reallocate(IronStack& Stack, int64_t new_capacity) {
    if (new_capacity < Size(Stack)) {
        perror("Need more space for the array");
    }

    StackElement* new_array = (StackElement*) realloc(Stack.array, new_capacity + N_CANARY);
    if (Stack.array == NULL) {
        perror("Stack is empty");
    }
    if (new_array == NULL) {
        IronStack NewStack = StackConstruct(Stack.size, new_capacity);
        for (size_t i = 0; i < Size(Stack); ++i) {
            NewStack.array[i] = Stack.array[i];
        }
        Check(NewStack);
        return NewStack;
    }

    Stack.array = new_array;
    Stack.begin = Stack.array + 1;
    Stack.capacity = new_capacity;
    Stack.begin[Stack.capacity] = Stack.CANARY;
    Check(Stack);
    return Stack;
}

void Check(IronStack& Stack) {
    if (*Stack.array != Stack.CANARY || Stack.begin[Stack.capacity] != Stack.CANARY) {
        perror("The data in the stack is invalid");
    }
}
