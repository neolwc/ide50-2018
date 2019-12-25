#include <stdio.h>
#include <cs50.h>

void printCharTimes(char ch, int times)
{
    for (int j = 0; j < times; j++)
    {
        printf("%c", ch);
    }
}


int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    for (int i = 1; i <= height; i++)
    {
        printCharTimes(' ', height - i);
        printCharTimes('#', i);
        printCharTimes(' ', 2);
        printCharTimes('#', i);
        printf("\n");
    }
}
