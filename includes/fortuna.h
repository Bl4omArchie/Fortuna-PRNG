#ifndef FORTUNA_H
#define FORTUNA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "crypto.h"


// --------- constants ---------

#define RET_OK 1                //c.1
#define RET_ERR -1              //c.2
#define COUNTER_BYTE_VALUE 16   //c.3


// --------- structures ---------

/* s.1
* key: a string
* counter: a 16-byte value treated as either an integer and a string using little-endian convention
*/
typedef struct _generate_state {
    char *key;
    uint8_t counter[16];
    hash_params_t *hash_state;
} g_state;


//s.2
typedef struct _prng_state {
    int reseed_count;
    int P;
    g_state generator_state;
} p_state;


// --------- functions  ---------

// f.1 Fortuna
int random_number(int bits);                       // f1.1: return a number of a given size
int write_random_number(int bits, char filename);  // f1.2: write a random int of the given int in the given filename


// f.2 Generator
int initialize_generator(g_state *state);                   // f2.1
int seed(g_state *state, char *seed);                       // f2.2
int iterate_counter(g_state *state);                        // f2.3
int generate_blocks(g_state *state, int k);                 // f2.4
int generate_pseudo_random_data(g_state *state, int bits);  // f2.5

// f.3 Accumulator
int initialize_prng(p_state *state);              // f3.1
int get_random_data(p_state *state, int bits);    // f3.2
int add_event();                                  // f3.3



#endif