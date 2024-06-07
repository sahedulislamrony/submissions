#include <cs50.h>
#include <stdio.h>
int get_start(void);
int get_end(void);
int start, end;
int main(void)
{
    start = get_start();
    end = get_end();
    int year = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        year++;
    }
    printf("Years: %i\n", year);
    return 0;
}
int get_start(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}
int get_end(void)
{
    int n;
    do
    {
        n = get_int("End size:  ");
    }
    while (n < start);
    return n;
}
