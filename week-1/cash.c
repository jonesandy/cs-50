// Works out how many coins to give
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Sets variables
    int change;
    int coins = 0;

    // Gets user input amount
    do
    {
        float input = get_float("Change owed: ");
        change = round(input * 100);
    }
    while (change <= 0);

    // Calculates how many coins needed
    while (change > 0)
    {
        if (change - 25 >= 0)
        {
            change = change - 25;
            coins++;
        }
        else if (change - 10 >= 0)
        {
            change = change - 10;
            coins++;          
        }
        else if (change - 5 >= 0)
        {
            change = change - 5;
            coins++;          
        }
        else
        {
            change = change - 1;
            coins++;            
        }
    }

    // Prints final total
    printf("%i\n", coins);
}
