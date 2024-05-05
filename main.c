#include "includes/fortuna.h"
#include "includes/crypto.h"

#include <stdio.h>


int test_prng() {
    // Initialize the generator state
    g_state generator;
    initialize_generator(&generator);

    // Display the initialized generator state
    printf("** Initialized Generator State **\n");
    printf("Key: %s\n", generator.key);


    printf("Counter: ");
    for (int i = 0; i < 16; i++) {
        printf("%02X ", generator.counter[i]);
    }
    printf("\n");
    
    for (int i=0; i<128; i++)
        iterate_counter(&generator);
    
    for (int i = 0; i < 16; i++) {
        printf("%02X ", generator.counter[i]);
    }
    printf("\n");
}


int test_hash() {
    g_state generator;
    char add_new_seed[SHA256_DIGEST_LENGTH];
    initialize_generator(&generator);
    
    for (int i=0; i<128; i++)
        iterate_counter(&generator);

    seed(&generator, add_new_seed);
}


int test_aes() {
    /*
    g_state generator;
    
    initialize_generator(&generator);
    
    for (int i=0; i<128; i++)
        iterate_counter(&generator);

    cipher_params_t = {.key = generator->key, .cipher_type=EVP_aes_256_cbc()}


    unsigned char *plaintext = (unsigned char *)generator->counter;

    unsigned char *ciphertext[128];
    int *ciphertext_len;

    */

    /* Encrypt the plaintext 
    ciphertext_len = encrypt_aes (plaintext, strlen ((char *)plaintext), key, ciphertext, ciphertext_len); */

    /* Do something useful with the ciphertext here
    printf("Ciphertext is:\n"); */
    
}


int main() {
    test_prng();
    test_hash();


    return 0;
}