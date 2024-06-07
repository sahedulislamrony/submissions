#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int areaySize, int bits[]);

int main(void)
{
    string mesg = get_string("Message: ");
    int len = strlen(mesg);
    int ascii; // for ASCII equivalent of characters
    int arSize = len * BITS_IN_BYTE;
    int bits[arSize]; // for storing all bits

    for (int i = 1; i <= len; i++)
    {
        ascii = mesg[i - 1];
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            bits[(BITS_IN_BYTE * i) - 1 - j] = ascii % 2;
            ascii = ascii / 2;
        }
    }

    print_bulb(arSize, bits);
}

void print_bulb(int arraySize, int bits[])
{

    for (int i = 0; i < arraySize; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf("\n");
        if (bits[i] == 1)
        {
            // Light emoji
            printf("\U0001F7E1");
        }
        else
        { // Dark emoji
            printf("\U000026AB");
        }
    }
    printf("\n");
}
