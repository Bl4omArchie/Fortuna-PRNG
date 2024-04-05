#include "fortuna.h"


int initialize_prng(p_state *state) {
    state->P = 0;
    state->reseed_count = 0;
    initialize_generator(&state->generator_state);
    return RET_OK;
}

int get_random_data(p_state *state, int bits) {

    return RET_OK;
}

int add_event() {

    return RET_OK;
}