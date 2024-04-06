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

    return 0;
}