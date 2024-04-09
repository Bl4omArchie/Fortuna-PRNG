# Implementation in C of Fortuna PRNG

I'm implementing Fortuna PRNG for self training purpose. <br/>
My reference is the following book: [Cryptography Engineering Design Principles and Practical Applications, Niels Ferguson, Bruce Schneier, Tadayoshi Kohno](https://www.schneier.com/wp-content/uploads/2015/12/fortuna.pdf)

# Listing

## fortuna.h
- Constants:
    ```
    - c.1: RET_OK
    - c.2: RET_ERR
    - c.3: COUNTER_BYTE_VALUE
    - c.4: MIN_POOL_SIZE
    ```

- Structures:
    ```
    - s.1: g_state
    - s.2: p_state
    ```
    
- Functions:
    - f.1: Fortuna
        ```
        - f1.1: random_number
        - f1.2: write_random_number
        ```

    - f.2: Generator
        ```
        - f.2.1: initialize_generator
        - f.2.2: seed
        - f.2.3: iterate_counter
        - f.2.4: generate_blocks
        - f.2.5: generate_pseudo_random_data
        ```

    - f.3 Accumulator
        ```
        - f.3.1: initialize_prng 
        - f.3.2: int get_random_data
        - f.3.3: add_event     
        ```

## crypto.h
- Constants:
    ```
    - c.1: RET_OK
    - c.2: RET_ERR
    - c.3: MAX_INPUT_LENGTH
    - c.4: SHA256_DIGEST_LENGTH
    ```

- Structures:
    ```
    - s.1: cipher_params_t
    ```
    
- Functions:
    - f.1: aes:
        ```
        - f.1.1: encrypt_aes
        - f.1.2: decrypt_aes
        - f.1.3: update_block_mode
        ```
    - f.2: sha256:
        ```
        - f.2.1: compute_sha256
        ```



// f.2: sha256
int compute_sha256(char *input, size_t input_len, char *output);
        ```

# Installation

You must install openssl library:
```
sudo apt install libssl-dev
```


# Sources

- [Cryptography Engineering Design Principles and Practical Applications, Niels Ferguson, Bruce Schneier, Tadayoshi Kohno](https://www.schneier.com/wp-content/uploads/2015/12/fortuna.pdf)
- [Encrypting/Decrypting a file using OpenSSL EVP](https://medium.com/@amit.kulkarni/encrypting-decrypting-a-file-using-openssl-evp-b26e0e4d28d4)