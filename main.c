#include "includes/fortuna.h"

#include <stdio.h>



int main() {
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



    /* hash a string
    char input[MAX_INPUT_LENGTH] = "test_string";
    char seed[MAX_INPUT_LENGTH] = "superseed"
    unsigned char output[SHA256_DIGEST_LENGTH];
    int i;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Update(&sha256, seed, strlen(seed));

    SHA256_Final(input, &sha256);
    */
    return 0;
}