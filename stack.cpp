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

uint64_t hashing (IronStack* Stack) {
    uint64_t hash = 0;
    for (int64_t i = 1; i <= Stack->size; ++i) {
        hash += i * Stack->array[i] + 7;
    }
    return hash % 103;
}

IronStack* StackConstruct(int64_t size, int64_t capacity) {
    IronStack* Stack = (IronStack*) calloc(1, sizeof(IronStack));
    Stack->capacity = capacity;
    Stack->array = (StackElement*) calloc(capacity + N_CANARY, sizeof(StackElement));
    if (Stack->array == NULL)
    {
        perror("Cannot allocate memory for stack.");
    }
    Stack->size = size;
    *Stack->array = Stack->CANARY;
    Stack->array[Stack->capacity + 1] = Stack->CANARY;
    Stack->hash = hashing(Stack);
    return Stack;
}

void StackDestructor(IronStack* Stack) {
    free(Stack->array);
}

void Push(IronStack* Stack, StackElement new_el) {
    uint64_t old_hash = Stack->hash;
    if (Stack->size + 1 > Stack->capacity) {
        IronStack* NewStack = Reallocate(Stack, MULTIPLIER * Stack->capacity);
    }

    ++Stack->size;
    Stack->array[Size(Stack)] = new_el;
    Stack->hash = hashing(Stack);
    if (hashing(Stack) != (old_hash + Stack->size * new_el + 7) % 103)
        perror("Problems with hash");
    Check(Stack);
}

StackElement Pop(IronStack* Stack) {
    uint64_t old_hash = Stack->hash;
    StackElement old_el = Stack->array[Size(Stack)];
    --Stack->size;
    Stack->hash = hashing(Stack);
    if (Stack->hash != (old_hash - (Stack->size + 1) * old_el - 7) % 103) {
        perror("Problems with hash");
    }
    Check(Stack);
    return old_el;
}

StackElement Top(IronStack* Stack) {
    Check(Stack);
    return Stack->array[Size(Stack)];
}

int64_t Size(IronStack* Stack) {
    Check(Stack);
    return Stack->size;
}

IronStack* Reallocate(IronStack* Stack, int64_t new_capacity) {
    uint64_t old_hash = Stack->hash;
    if (new_capacity < Size(Stack)) {
        perror("Need more space for the array");
    }

    StackElement* new_array = (StackElement*) realloc(Stack->array, (new_capacity + N_CANARY) * sizeof(StackElement));
    if (Stack->array == NULL) {
        perror("Stack is empty");
    }
    if (new_array == NULL) {
        IronStack* NewStack = StackConstruct(Stack->size, new_capacity);
        for (int64_t i = 0; i < Size(Stack); ++i) {
            NewStack->array[i] = Stack->array[i];
        }
        Check(NewStack);
        if (hashing(Stack) != old_hash) {
            perror("Problems with hash");
        }
        return NewStack;
    }

    Stack->array = new_array;
    Stack->capacity = new_capacity;
    Stack->array[Stack->capacity + 1] = Stack->CANARY;
    Stack->hash = hashing(Stack);
    Check(Stack);
    if (hashing(Stack) != old_hash) {
        perror("Problems with hash");
    }
    return Stack;
}

void Check(IronStack* Stack) {
    if (Stack->array[0] != Stack->CANARY || Stack->array[Stack->capacity + 1] != Stack->CANARY) {
        perror("The data in the stack is invalid");
    }
}
