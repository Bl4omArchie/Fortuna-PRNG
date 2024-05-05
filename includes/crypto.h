#ifndef CRYPTO_H
#define CRYPTO_H

#include <openssl/aes.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <string.h>

#include "fortuna.h"


// The crypto header is made for prototypes using openSSL library


/*
Because of the following warning: ‘AES_set_encrypt_key’ is deprecated: Since OpenSSL 3.0
We shall no longer access directly cryptographic primitives like RSA, EC or AES but use EVP which is an API in a higher level.
In consequence the code below is not good :/

Sources: 
- https://github.com/pocoproject/poco/issues/3516
- https://stackoverflow.com/questions/76212694/what-is-the-exact-alternative-to-using-aes-set-encrypt-key-in-openssl-3x
*/



// --------- structures  ---------

typedef struct _cipher_params_t{
    unsigned char *key;
    unsigned char *iv;
    unsigned int encrypt;
    const EVP_CIPHER *cipher_type;
} cipher_params_t;


// --------- functions ---------

// f.4.1: AES
int encrypt_aes(cipher_params_t *cipher_data, g_state generator, char *ciphertext, int *ciphertext_len);
int decrypt_aes(cipher_params_t *cipher_data, char ciphertext, char *plaintext);
int update_block_mode(cipher_params_t *cipher_data, EVP_CIPHER *cipher_mode);


#endif