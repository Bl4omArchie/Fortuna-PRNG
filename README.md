# Implementation in C of Fortuna PRNG

I'm implementing Fortuna PRNG for self training purpose. <br/>
My reference is the following book: [Cryptography Engineering Design Principles and Practical Applications, Niels Ferguson, Bruce Schneier, Tadayoshi Kohno](https://www.schneier.com/wp-content/uploads/2015/12/fortuna.pdf)

# Listing

- Constants:
    ```
    - c.1: RET_OK
    - c.2: RET_ERR
    - c.3: COUNTER_BYTE_VALUE
    ```

- Structures:
    ```
    - s.1: g_state
    - s.2: p_state
    - s.3: cipher_params_t
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

    - f.4 Crypto
        ```
        - f.4.1 encrypt_aes
        - f.4.2 decrypt_aes
        - f.4.3 update_block_mode
        ```



# Installation

You must install openssl library:
```
sudo apt install libssl-dev
```


# Sources

- [Cryptography Engineering Design Principles and Practical Applications, Niels Ferguson, Bruce Schneier, Tadayoshi Kohno](https://www.schneier.com/wp-content/uploads/2015/12/fortuna.pdf)
- [Encrypting/Decrypting a file using OpenSSL EVP by Amit Kulkarni](https://medium.com/@amit.kulkarni/encrypting-decrypting-a-file-using-openssl-evp-b26e0e4d28d4)
- [openSSL - EVP documentation](https://wiki.openssl.org/index.php/EVP)