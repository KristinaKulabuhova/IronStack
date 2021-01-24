#include "Stack.h"

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

    IronStack StackConstuct(int64_t size, int64_t capacity){
    IronStack Stack;
    Stack.capacity = capacity;
    Stack.array = (int*) calloc(capacity + N_CANARY, sizeof(StackElement));
    if (Stack.array == NULL)
    {
        perror("Cannot allocate memory for stack.");
    }
    Stack.size = size;
    Stack.array[0] = Stack.CANARY;
    Stack.array[Stack.capacity] = Stack.CANARY; 
}

void Push(IronStack Stack, StackElement new_el) {
    if(Stack.size + 1 < Stack.capacity) {
        IronStack NewStack = Reallocate(Stack, MULTIPLIER * Stack.capacity);
    }
    else {
        Stack.array[Size(Stack)] = new_el;
        ++Stack.size;
    }
    Check(Stack);
}

StackElement Pop(IronStack Stack) {
    StackElement old_el = Stack.array[Size(Stack)];
    --Stack.size;
    Check(Stack);
    return old_el;
}

StackElement Top(IronStack Stack) {
    Check(Stack);
    return Stack.array[Size(Stack)];
}

int64_t Size(IronStack Stack) {
    Check(Stack);
    return Stack.size;
}

IronStack Reallocate(IronStack Stack, int64_t new_capacity) {
    if (new_capacity < Size(Stack) + 2) {
        perror("Need more space for the array.");
    }

    StackElement* new_array = (StackElement*) realloc(Stack.array, new_capacity);
    if (new_array != NULL) {
        Stack.array = new_array;
        Stack.capacity = new_capacity;
        Check(Stack);
        return Stack;
    }

    IronStack NewStack = StackConstuct(Stack.size, new_capacity);
    for(size_t i = 0; i < Size(Stack); ++i) {
        NewStack.array[i] = Stack.array[i];
    }
    Stack.array[Stack.capacity - 1] = Stack.CANARY;
    Check(Stack);
    return Stack;
}

void Check(IronStack Stack) {
    if (Stack.array[0] != Stack.CANARY || Stack.array[Stack.capacity - 1] != Stack.CANARY) {
        perror("The data in the stack is invalid.");
    }
}
