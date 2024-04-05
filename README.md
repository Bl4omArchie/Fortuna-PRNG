# Implementation in C of Fortuna PRNG

I'm implementing Fortuna PRNG for self training purpose. <br/>
My reference is the following book: [Cryptography Engineering Design Principles and Practical Applications, Niels Ferguson, Bruce Schneier, Tadayoshi Kohno](https://www.schneier.com/wp-content/uploads/2015/12/fortuna.pdf)

# Listing

## fortuna.h
- Constants:
    - c.1: RET_OK
    - c.2: RET_ERR

- Structures:
    - s.1: _generator_State
    - s.2: _PRNG_state

- Functions:
    - f.1: Fortuna
        - f1.1: random_number
        - f1.2: write_random_number
    
    - f.2: Generator
        - f.2.1: initialize_generator
        - f.2.2: seed
        - f.2.3: iterate_counter
        - f.2.4: generate_blocks
        - f.2.5: generate_pseudo_random_data

    - f.3 Accumulator
        - f.3.1: initialize_prng 
        - f.3.2: int get_random_data
        - f.3.3: add_event

# Installation

You must install openssl library:
```
sudo apt install libssl-dev
```


# Sources

- [Cryptography Engineering Design Principles and Practical Applications, Niels Ferguson, Bruce Schneier, Tadayoshi Kohno](https://www.schneier.com/wp-content/uploads/2015/12/fortuna.pdf)
- [Encrypting/Decrypting a file using OpenSSL EVP](https://medium.com/@amitkulkarniencrypting-decrypting-a-file-using-openssl-evp-b26e0e4d28d4)