#include "stack.h";
#include "test.h"
#define StackElement int;

#ifdef TEST_BUILD
void Tests() {
    if (Test_StackConstruct(5, 7)) {
        printf ("%s","Test №1 is TRUE");
    }
    else {
        printf ("%s","Test №1 is FALSE");
    }

    IronStack Stack = StackConstruct(5, 7);

    if (Test_Push(Stack, 2)) {
        printf ("%s","Test №2 is TRUE");
    }
    else {
        printf ("%s","Test №2 is FALSE");
    }

    if (Test_Pop(Stack)) {
        printf ("%s","Test №3 is TRUE");
    }
    else {
        printf ("%s","Test №3 is FALSE");    
    }

    if (Test_Top(Stack)) {
        printf ("%s","Test №4 is TRUE");
    }
    else {
        printf ("%s","Test №4 is FALSE");
    }

    if (Test_Size(Stack)) {
        printf ("%s","Test №5 is TRUE");
    }
    else {
        printf ("%s","Test №5 is FALSE");
    }

   if (Test_Reallocate(Stack, 10)) {
        printf ("%s","Test №6 is TRUE");
    }
    else {
        printf ("%s","Test №6 is FALSE");
   }

    if (Test_Reallocate(Stack, 6)) {
        printf ("%s","Test №7 is TRUE");
    }
    else {
        printf ("%s","Test №7 is FALSE");
    }

    if (Test_Check(Stack)) {
         printf ("%s","Test №8 is TRUE");
    }
    else {
        printf ("%s","Test №8 is FALSE");
    }
}

#endif

int main() {
    #ifdef TEST_BUILD
    Test();
    #endif
}
