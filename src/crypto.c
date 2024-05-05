#include "crypto.h"



int encrypt_aes(cipher_params_t *cipher_data, g_state generator, char *ciphertext, int *ciphertext_len) {

    cipher_data->encrypt = 1;

    return RET_OK;
}

int decrypt_aes(cipher_params_t *cipher_data, char ciphertext, char *plaintext) {


    return RET_OK;
}

int update_block_mode(cipher_params_t *cipher_data, EVP_CIPHER *cipher_mode) {
    if (cipher_data == NULL || cipher_mode == NULL)
        return RET_ERR;
    
    cipher_data->cipher_type = cipher_mode;
    return RET_OK;
}