#include <stdio.h>
#include <sodium.h>

void print_hex_hash(unsigned char* data) {
    unsigned int i;
    for (i = 0; i < crypto_generichash_BYTES; i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
}
