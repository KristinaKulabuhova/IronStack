#ifndef HASH_H
#define HASH_H

#include <unordered_map>
#include "stack.h"

int64_t array_hashing(const StackElement* array, int64_t size);
StackElement* fill_array(StackElement* array, int64_t size);

std::unordered_map<int64_t, int64_t> Test_Hash(int64_t size, int64_t counter);
void write_in_file(std::unordered_map<int64_t, int64_t> map);

#endif //IRON_STACK_HASH_H
