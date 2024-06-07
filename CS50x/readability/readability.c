#include <cs50.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sente = count_sentences(text);

    double L = ((double) letters / words) * 100;
    double S = ((double) sente / words) * 100;

    double index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index >= 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %.0lf\n", index);

    return 0;
}

int count_letters(string text)
{
    int count = 0;
    char c;
    for (int i = 0; text[i] != '\0'; i++)

    {
        c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            count++;
    }
    return count;
}

int count_words(string text)
{

    int count = 1; // for counting first word

    for (int i = 0; text[i] != '\0'; i++)

    {
        if (text[i] == ' ')
            count++;
    }
    return count;
}

int count_sentences(string text)
{

    int count = 0;
    char c;

    for (int i = 0; text[i] != '\0'; i++)

    {
        c = text[i];
        if (c == '.' || c == '!' || c == '?')
            count++;
    }
    return count;
}
