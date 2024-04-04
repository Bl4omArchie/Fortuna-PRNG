#ifndef FORTUNA_H
#define FORTUNA_H

#include <stdlib.h>
#include <stdint.h>


// --------- constants ---------

#define RET_OK 1    //c.1
#define RET_ERR -1  //c.2


// --------- structures ---------

//s.1
typedef struct Generate_State{
    char *key;
    char *counter;
} Gstate;

//s.2
typedef struct PRNG_state {
    int reseed_count;
    int P;
    Gstate state;
} Pstate;


// --------- functions  ---------

// f.1 Fortuna
int random_number(int bits);                       // f1.1: return a number of a given size
int write_random_number(int bits, char filename);  // f1.2: write a random int of the given int in the given filename


// f.2 Generator
int initialize_generator(Gstate state);                   // f2.1
int seed(Gstate state, int seed);                         // f2.2
int iterate_counter();                                    // f2.3
int generate_blocks(Gstate state, int k);                 // f2.4
int generate_pseudo_random_data(Gstate state, int bits);  // f2.5

// f.3 Accumulator
int initialize_prng(Pstate state);              // f3.1
int get_random_data(Pstate state, int bits);    // f3.2
int add_event();                                // f3.3



#endif