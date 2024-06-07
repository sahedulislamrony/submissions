
#include <cs50.h>
#include <stdio.h>
int input_height(void);
int main()
{
    int height = input_height();
    int count = 1;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < (height - count); j++)
        {
            printf(" "); // print white space before #
        }

        for (int k = 0; k < count; k++)
        {
            printf("#");
        }

        printf("\n");
        count++;
    }
    return 0;
}

int input_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}
