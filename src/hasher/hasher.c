#include <stdlib.h>
#include <string.h>
#include <sodium.h>

#define CHUNK_SIZE 256

void generic_hash(
        const unsigned char* str, 
        const unsigned long long str_size,
        unsigned char hash[]
    ) {
    
    unsigned char* key = NULL;
    unsigned long long key_size = 0;

    crypto_generichash_state state;
    crypto_generichash_init(&state, key, key_size, crypto_generichash_BYTES);
    
    unsigned int mod = str_size % CHUNK_SIZE;
    unsigned int extra_chunk = mod != 0 ? 1 : 0;
    
    unsigned long long chunks;
    if (mod == 0) {
        chunks = str_size / CHUNK_SIZE;
    } else {
        chunks = str_size / CHUNK_SIZE + 1;
    }

    int i;
    unsigned int sz;
    for (i = 0; i < chunks; i++) {
        unsigned int is_last_iter = (i+1) == chunks;
        unsigned long long pos = i * CHUNK_SIZE;

        if (mod == 0) {
            sz = CHUNK_SIZE;
        } else {
            sz = is_last_iter ? mod : CHUNK_SIZE;
        }
        crypto_generichash_update(&state, &str[pos], sz);
    }

    crypto_generichash_final(&state, hash, crypto_generichash_BYTES);
}