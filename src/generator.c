#include "fortuna.h"
#include "crypto.h"



int initialize_generator(g_state *state) {
    state->key = "0";
    memset(state->counter, 0, sizeof(state->counter));

    return RET_OK;
}


int seed(g_state *state, char *seed) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;

    mdctx = EVP_MD_CTX_new();
    md = EVP_sha256();

    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, state->key, sizeof(state->key));
    EVP_DigestFinal_ex(mdctx, seed, sizeof(seed));

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