// Prints hashes in a pyramid
#include <cs50.h>
#include <stdio.h>

void print_right_half(int n);
void print_left_spaces(int n, int m);
void print_left_hashes(int n);

int main(void)
{
    int number;
    do
    {
        number = get_int("Height: ");
    }
    while (number < 1 || number > 8);

    for (int i = 0; i < number; i++)
    {
        // Uses the defined functions
        print_left_spaces(i, number);
        print_left_hashes(i);
        print_right_half(i);
        printf("\n");
    }
}

// Prints right half bank of hashes
void print_right_half(int n)
{
    printf("  ");
    for (int j = 0; j <= n; j++)
    {
        printf("#");
    }
}

// Prints leading spaces
void print_left_spaces(int n, int m)
{
    for (int k = n + 1; k < m; k++)
    {
        printf(" ");
    }
}

// Prints left bank of hashes
void print_left_hashes(int n)
{
    for (int j = 0; j <= n; j++)
    {
        printf("#");
    }
}
