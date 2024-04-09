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
    
    iterate_counter(&generator);
    for (int i = 0; i < 16; i++) {
        printf("%02X ", generator.counter[i]);
    }
    printf("\n");



    // hash a string
    char input[MAX_INPUT_LENGTH];
    unsigned char output[SHA256_DIGEST_LENGTH];
    int i;

    printf("Enter the string to hash: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    compute_sha256(input, strlen(input), output);

    printf("SHA-256 hash of '%s' is: ", input);
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}