#include <stdio.h>
#include <string.h>
#include <sodium.h>
#include "../hasher/hasher.h"
#include "utils.h"

#define RETCODE_SUCCESS 0
#define RETCODE_USAGE 1
#define RETCODE_SODIUM_PANIC 2

// ~/hdd/ndk-x86/bin/clang -Os ./src/main.c ./src/hasher.c ./src/utils.c ./lib/libsodium.a

extern void generic_hash(const unsigned char*, unsigned long long, unsigned char hash[]);

int main(int argc, char **argv) {
    
    if (argc < 2) {
        printf("%s input_string\n", argv[0]);
        return RETCODE_USAGE;
    }

    if (sodium_init() < 0) {
        printf("libsodium couldn't be initialized\n");
        return RETCODE_SODIUM_PANIC;
    }

    unsigned char hash[crypto_generichash_BYTES];
    generic_hash((const unsigned char*)argv[1], strlen(argv[1]), hash);
    print_hex_hash(hash);

    return RETCODE_SUCCESS;
}
