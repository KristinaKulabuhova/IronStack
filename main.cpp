#include "stack.h"
#include "test.h"
#define StackElement int;

#ifdef TEST_BUILD
void Tests() {
    if (Test_StackConstruct(5, 7)) {
        printf ("%s","Test 1 is TRUE\n");
    }
    else {
        printf ("%s","Test 1 is FALSE\n");
    }

    IronStack* Stack = StackConstruct(6, 7);

    if (Test_Push(Stack, 2)) {
        printf ("%s","Test 2 is TRUE\n");
    }
    else {
        printf ("%s","Test 2 is FALSE\n");
    }

    if (Test_Push(Stack, 4)) {
        printf ("%s","Test 3 is TRUE\n");
    }
    else {
        printf ("%s","Test 3 is FALSE\n");
    }

    if (Test_Pop(Stack)) {
        printf ("%s","Test 4 is TRUE\n");
    }
    else {
        printf ("%s","Test 4 is FALSE\n");
    }

    if (Test_Top(Stack)) {
        printf ("%s","Test 5 is TRUE\n");
    }
    else {
        printf ("%s","Test 5 is FALSE\n");
    }

    if (Test_Size(Stack)) {
        printf ("%s","Test 6 is TRUE\n");
    }
    else {
        printf ("%s","Test 6 is FALSE\n");
    }

    if (Test_Reallocate(Stack, 10)) {
        printf ("%s","Test 7 is TRUE\n");
    }
    else {
        printf ("%s","Test 7 is FALSE\n");
    }

    Pop(Stack);
    if (Test_Reallocate(Stack, 6)) {
        printf ("%s","Test 8 is TRUE\n");
    }
    else {
        printf ("%s","Test 8 is FALSE\n");
    }

    if (Test_Check(Stack)) {
         printf ("%s","Test 9 is TRUE\n");
    }
    else {
        printf ("%s","Test 9 is FALSE\n");
    }
    StackDestructor(Stack);
}

#endif

int main() {
    #ifdef TEST_BUILD
    Tests();
    #endif
}
