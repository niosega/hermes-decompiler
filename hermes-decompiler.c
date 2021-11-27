#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "utils.h"

#define EXPECTED_MAGIC 2240826417119764422
#define SUPPORTED_VERSION 74

void load(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Fail to open file %s\n", filename);
        exit(EXIT_FAILURE); 
    }

    // Check if magic number is correct.
    uint64_t magic = read_uint64(fp);
    if (magic != EXPECTED_MAGIC) {
        printf("Found magic number is different from expected. Found %ld Expected %ld.\n", magic, EXPECTED_MAGIC);
        exit(EXIT_FAILURE);
    } else {
        printf("Magic number match.\n");
    }

    // Query version.
    uint32_t version = read_uint32(fp);
    if (version != SUPPORTED_VERSION) {
        printf("Only supported version is %d. Found %d.\n", SUPPORTED_VERSION, version);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Please specify file to decompile.\n");
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    printf("Decompiling %s\n", filename);
    load(filename);
    return 0;
}