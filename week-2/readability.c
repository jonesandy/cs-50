// Knows how to grade some text
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes for custom functions
int count_letters(string text);
int count_words(string text);
int sentence_count(string text);
float calculate_l(int letters, int words);
float calculate_s(int sentences, int words);
void print(float index);


int main(void)
{
    // Get a string to analyse
    string text = get_string("Text: ");

    // Calculates letters, words and sentences
    int number_of_letters = count_letters(text);
    int number_of_words = count_words(text);
    int number_of_sentences = sentence_count(text);

    // Calculates per 100 words each part needed for formula
    float L = calculate_l(number_of_letters, number_of_words);
    float S = calculate_s(number_of_sentences, number_of_words);

    // Coleman-Liau index
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Runs the print function
    print(index);
}

// Counts letters for the text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Counts the words for the text
int count_words(string text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Counts sentences for the text
int sentence_count(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

float calculate_l(int letters, int words)
{
    float x = ((float) letters / words) * 100;
    return x;
}

float calculate_s(int sentences, int words)
{
    float x = ((float) sentences / words) * 100;
    return x;
}

// Print function for text. Doesn't return anything.
void print(float index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)index);
    }
}