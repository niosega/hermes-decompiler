#include <stdio.h>
#include <stdint.h>

uint32_t read_uint32(FILE* fp) {
    char tmp[4];
    fread(tmp, 4, 1, fp);
    return *((uint32_t*) tmp);
}

uint64_t read_uint64(FILE* fp) {
    char tmp[8];
    fread(tmp, 8, 1, fp);
    return *((uint64_t*) tmp);
}