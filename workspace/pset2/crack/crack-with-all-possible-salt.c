#define MAX_LENGTH 5
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lenofchar(int len, char c);
void prev(char **curr, char firstchar);
bool compare(char *guess, char *input);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    char *last = lenofchar(MAX_LENGTH + 1, 'A');
    do
    {
        prev(&last, 'A');
        if (compare(argv[1], last))
        {
            printf("%s\n", last);
            return 0;
        }
    }
    while (strcmp(last, "A") != 0);
}

char *lenofchar(int len, char c)
{
    char *result = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        *(result + i) = c;
    }
    *(result + len) = '\0';
    return result;
}

void prev(char **curr, char firstchar)
{
    int len = strlen(*curr);
    char *allAsatlen = lenofchar(len, firstchar);

    if (strcmp(*curr, allAsatlen) == 0)
    {
        *curr = lenofchar(len - 1, 'z');
    }
    else
    {
        char *target = *curr + (len - 1);

        while (*target == firstchar)
        {
            *target = 'z';
            target --;
        }

        if (*target == 'a')
        {
            *target = 'Z';
        }
        else if (*target == 'A' && firstchar != 'A')
        {
            *target = '9';
        }
        else
        {
            *target = *target - 1;
        }
    }

    free(allAsatlen);
}

bool compare(char *guess, char *input)
{
    char *salt = lenofchar(2, 'z');
    do
    {
        printf("%s\n", salt);
        char *hash = crypt(guess, salt);
        printf("%s\n", hash);
        if (strcmp(hash, input) == 0)
        {
            return true;
        }
        prev(&salt, '.');
    }
    while(strcmp(salt, "z") != 0);

    free(salt);
    return true;
}
