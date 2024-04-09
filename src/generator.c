#include "fortuna.h"



int initialize_generator(g_state *state) {
    state->key = "0";
    memset(state->counter, 0, sizeof(state->counter));

    return RET_OK;
}


int seed(g_state *state, char seed) {
    char input[MAX_INPUT_LENGTH];
    input = state->key | seed;

    compute_sha256(input, strlen(input), state->key);
    iterate_counter(state);

    return RET_OK;
}

int iterate_counter(g_state *state) {
    uint16_t sum;
    int carry = 1;

    for (int i=0; i<COUNTER_BYTE_VALUE; i++) {
        sum = state->counter[i] + carry;
        state->counter[i] = sum & 0xFF;
        carry >>= 8;
    }

    return RET_OK;
}

int generate_blocks(g_state *state, int k) {

    return RET_OK;
}

int generate_pseudo_random_data(g_state *state, int bits) {

    return RET_OK;
}