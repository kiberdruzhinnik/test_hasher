#include <string.h>
#include <sodium.h>
#include "greatest.h"
#include "../hasher/hasher.h"

int internal_test(const char* input_first, const char* input_second) {
    unsigned char hash_actual[crypto_generichash_BYTES];
    unsigned char hash_expected[crypto_generichash_BYTES];

    unsigned long long input_len = strlen(input_first);

    generic_hash((const unsigned char*)input_first, input_len, hash_actual);
    crypto_generichash(hash_expected, sizeof hash_expected, (const unsigned char*)input_second, input_len, NULL, 0);

    int i;
    for (i = 0; i < crypto_generichash_BYTES; i++) {
        if (hash_actual[i] != hash_expected[i]) {
            return 0;
        }
    }

    return 1;
}

int internal_test_equal(const char* input) {
    return internal_test(input, input);
}

TEST simple_equal_test(void) {
    if (internal_test_equal("1")) {
        PASS();
    }
    FAIL();
}

TEST mod_zero_test(void) {
    if (internal_test_equal("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111")) {
        PASS();
    }
    FAIL();
}

TEST mod_zero_plus_one_test(void) {
    if (internal_test_equal("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111")) {
        PASS();
    }
    FAIL();
}

TEST not_equal_test(void) {
    if (!internal_test("1", "2")) {
        PASS();
    }
    FAIL();
}

SUITE(the_suite) {
    RUN_TEST(simple_equal_test);
    RUN_TEST(mod_zero_test);
    RUN_TEST(mod_zero_plus_one_test);
    RUN_TEST(not_equal_test);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    if (sodium_init() < 0) {
        printf("libsodium couldn't be initialized\n");
        return 1;
    }

    RUN_SUITE(the_suite);
    GREATEST_MAIN_END();
}