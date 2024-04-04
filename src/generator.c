#include "fortuna.h"




int initialize_generator(Gstate state) {
    state.key = "";
    state.counter = "";

    return RET_OK;
}


int seed(Gstate state, int seed) {

    return RET_OK;
}