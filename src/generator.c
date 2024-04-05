#include "fortuna.h"




int initialize_generator(g_state *state) {
    state->key = "\0x00";
    state->counter = "\0x00";
    return RET_OK;
}


int seed(g_state *state, int seed) {

    return RET_OK;
}