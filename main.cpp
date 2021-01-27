#include "stack.h"
#include "test.h"
#include "hash.h"

#define StackElement int;

#define TEST(FUNCTION, TEST_NAME) if((FUNCTION)) { printf ("Test " TEST_NAME " passed\n"); } else { printf ("Test " TEST_NAME " failed\n"); }

#ifdef TEST_BUILD
void Tests() {
    TEST(Test_StackConstruct(5, 7), "CONSTRUCT");
    IronStack* Stack = StackConstruct(6, 7);
    TEST(Test_Push(Stack, 2),"PUSH");
    TEST(Test_Push(Stack, 4), "PUSH")
    TEST(Test_Pop(Stack), "POP");
    TEST(Test_Top(Stack), "TOP");
    TEST(Test_Size(Stack), "SIZE");
    TEST(Test_Reallocate(Stack, 10), "REALLOCATE");
    Pop(Stack);
    TEST(Test_Reallocate(Stack, 6), "REALLOCATE");
    TEST(Test_Check(Stack), "CHECK");

    StackDestructor(Stack);
}
#endif

int main() {
    #ifdef TEST_BUILD
    Tests();
    #endif

    Test_Hash(100, 10000);
}
