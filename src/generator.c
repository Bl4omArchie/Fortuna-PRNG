#include "fortuna.h"



int initialize_generator(g_state *state) {
    state->key = "0";
    memset(state->counter, 0, sizeof(state->counter));

    return RET_OK;
}


int seed(g_state *state, char *seed) {
    create_hash(state->hash_state, EVP_sha256());

    EVP_DigestUpdate(state->hash_state->md_ctx, state->key, sizeof(state->key));
    EVP_DigestUpdate(state->hash_state->md_ctx, seed, sizeof(seed));

    iterate_counter(state);

    return RET_OK;
}


int iterate_counter(g_state *state) {
    uint16_t sum;
    int carry = 1;

    for (int i=0; i < COUNTER_BYTE_VALUE; i++) {
        // store the addition in a 16 bit variable to avoid overflow
        sum = state->counter[i] + carry;

        // place the result in the counter with a 8 bit mask 
        state->counter[i] = sum & 0xFF; 

        // check if we need a carry for the next round 
        carry = (sum > 0xFF - carry) ? 1 : 0;
    }
    return RET_OK;
}


int generate_blocks(g_state *state, int k) {

    return RET_OK;
}

int generate_pseudo_random_data(g_state *state, int bits) {

    return RET_OK;
}