#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
int error(void);
void print_cipher(string plaintext, int key);

// Main function
int main(int argc, string argv[])
{
    // Guard clause against wrong number of arguments
    if (argc != 2)
    {
        return error();
    }

    // Gets the string version of the key
    string input_key = argv[1];

    // Checks if key contains any illegal chars
    for (int i = 0, n = strlen(input_key); i < n; i++)
    {
        if (isalpha(input_key[i]))
        {
            return error();
        }
    }

    int key = atoi(input_key);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    print_cipher(plaintext, key);
    printf("\n");

}


// Prints an error message if not run correctly
int error(void)
{
    printf("ERROR!\nUsage: ./caesar key\nKey should be an integer\n");
    return 1;
}

void print_cipher(string plaintext, int key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if (plaintext[i] > 64 && plaintext[i] < 91)
        {
            printf("%c", ((((plaintext[i] - 65) + key)) % 26) + 65);
        }
        else
        {
            printf("%c", ((((plaintext[i] - 97) + key)) % 26) + 97);
        }
    }
}