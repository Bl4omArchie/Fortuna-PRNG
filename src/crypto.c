#include "crypto.h"



int encrypt_aes(cipher_params_t *cipher_data, char plaintext, char *ciphertext) {


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


int create_hash(hash_params_t *hash_data, const EVP_MD *hash) {
    if (hash_data == NULL || hash == NULL)
        return RET_ERR;

    hash_data->md_ctx = EVP_MD_CTX_new();
    hash_data->hash_function = hash;
    EVP_DigestInit_ex(hash_data->md_ctx, hash_data->hash_function, NULL);

    return RET_OK;
}