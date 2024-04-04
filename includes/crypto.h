#ifndef CRYPTO_H
#define CRYPTO_H

#include <openssl/aes.h>
#include <string.h>

// --------- constants ---------

#define RET_OK 1    //c.1
#define RET_ERR -1  //c.2


// --------- functions ---------

int chiffrer_aes(char *chaine_claire, char *clef, char *vecteur_initialisation, char *chaine_chiffree);

#endif