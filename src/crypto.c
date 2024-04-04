#include "crypto.h"

/*
Because of the following warning: warning: ‘AES_set_encrypt_key’ is deprecated: Since OpenSSL 3.0
We shall no longer access directly cryptographic primitives like RSA, EC or AES but use EVP which is an API in a higher level.
In consequence the code below is not good :/

Sources: 
- https://github.com/pocoproject/poco/issues/3516
- https://stackoverflow.com/questions/76212694/what-is-the-exact-alternative-to-using-aes-set-encrypt-key-in-openssl-3x
*/

// Fonction pour chiffrer une chaîne avec AES-256-CBC
int chiffrer_aes(char *chaine_claire, char *clef, char *vecteur_initialisation, char *chaine_chiffree) {
    AES_KEY aes_key;
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char ciphertext[strlen(chaine_claire) + 1];
    int longueur_ciphertext;

    // Conversion de la clé et du vecteur d'initialisation en format binaire
    if (AES_set_encrypt_key((unsigned char *)clef, 256, &aes_key) != 0) 
        return RET_ERR;


    memcpy(iv, vecteur_initialisation, AES_BLOCK_SIZE);
    AES_cbc_encrypt((unsigned char *)chaine_claire, ciphertext, strlen(chaine_claire), &aes_key, iv, AES_ENCRYPT);

    ciphertext[longueur_ciphertext] = '\0';
    strcpy(chaine_chiffree, (char *)ciphertext);

    return RET_OK;
}