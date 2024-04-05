#include "fortuna.h"




int initialize_generator(g_state state) {
    state.key = "";
    state.counter = "";

    return RET_OK;
}


int seed(g_state state, int seed) {

    return RET_OK;
}