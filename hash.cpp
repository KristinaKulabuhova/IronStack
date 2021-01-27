#include <stdio.h>
#include "hash.h"

int64_t array_hashing(const StackElement* array, int64_t size) {
    int64_t hash = 0;
    for (int64_t i = 0; i < size; ++i) {
        hash += i * array[i] + 7;
    }

    return hash % 103;
}

StackElement* fill_array(StackElement* array, int64_t size) {
    for (int64_t i = 0; i < size; ++i) {
        array[i] = rand();
    }

    return array;
}

std::unordered_map<int64_t, int64_t> Test_Hash(int64_t array_size, int64_t counter) {
    StackElement* array = (StackElement*) calloc(array_size, sizeof(StackElement));
    std::unordered_map<int64_t, int64_t> map = {};

    for (int64_t i = 0; i < counter; ++i) {
        fill_array(array, array_size);
        int64_t res_hash = array_hashing(array, array_size);
        ++map[res_hash];
    }

    write_in_file(map);
    free(array);

    return map;
}

void write_in_file(std::unordered_map<int64_t, int64_t> map) {
    FILE *file = NULL;
    file = fopen("hash.txt", "w");

    if (file == NULL) {
        perror("Cannot open the file");

        return;
    }
    for (auto iter = map.begin(); iter != map.end(); ++iter) {
        fprintf(file, "%lld %lld\n", iter->first, iter->second);
    }

    fclose(file);
}