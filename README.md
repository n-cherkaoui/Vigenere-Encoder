## Vigenere-Encoder
This is a C program that takes in a key and a message as files, and encrypts the message using the Vigenere cipher. 
The program removes any non-alphabetic characters from the message, pads it with X's until it is a multiple of the key's length, 
and then encrypts it using the Vigenere cipher algorithm. The resulting ciphertext is displayed.

## Getting Started
1. Clone this repository.
2. Compile the program using a C compiler.
3. Run the executable file.

## Usage
To use this algorithm, you will need to provide two input txt files: one containing a plaintext message and the other containing an encryption key.
Sample input files are provided. Files beginning with `k` are example keys, while those beginning with `p` are plaintexts. For example, you can use `k1.txt` and `p1.txt`.

Once you have your input file ready, you can run the following commands to begin the program:

```
gcc Vigenere.c -o ./vigenere
./vigenere kX.txt pX.txt
```

