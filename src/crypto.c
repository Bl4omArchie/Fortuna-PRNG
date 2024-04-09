#include "crypto.h"



int encrypt_aes(cipher_params_t *cipher_data, char plaintext, char *ciphertext) {


    return RET_OK;
}

int decrypt_aes(cipher_params_t *cipher_data, char ciphertext, char *plaintext) {


    return RET_OK;
}

int update_block_mode(cipher_params_t *cipher_data, EVP_CIPHER *cipher_mode) {
    if (cipher_mode == NULL)
        return RET_ERR;
    
    cipher_data->cipher_type = cipher_mode;
    return RET_OK;
}

int compute_sha256(char *input, size_t input_len, char *output) {
    EVP_MD_CTX *mdctx;

    if ((mdctx = EVP_MD_CTX_new()) == NULL) {
        printf("Error in EVP_MD_CTX_new()\n");
        return RET_ERR;
    }

    if (!EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)) {
        printf("Error in EVP_DigestInit_ex()\n");
        return RET_ERR;
    }

    if (!EVP_DigestUpdate(mdctx, input, input_len)) {
        printf("Error in EVP_DigestUpdate()\n");
        return RET_ERR;
    }

    if (!EVP_DigestFinal_ex(mdctx, output, NULL)) {
        printf("Error in EVP_DigestFinal_ex()\n");
        return RET_ERR;
    }

    EVP_MD_CTX_free(mdctx);
    return RET_OK;
}