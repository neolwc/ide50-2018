#define _XOPEN_SOURCE
#define MAX_LENGTH 5
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void next(string current);
void prev(char *current[6]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        char last[MAX_LENGTH + 1];
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            last[i] = 'z';
        }
        last[MAX_LENGTH] = '\0';

        string test = "A";
        do
        {
            printf("%s\n", last);
            prev(&last);

            printf("%s\n", last);
            // next(test);
        }
        while (test != last);
        // for (int length = 1; length <= MAX_LENGTH; length++)
        // {
        //     string test;
        //     for (int i = 0; i < length; i++)
        //     {

        //     }
        // }
        // printf("%i\n", MAX_LENGTH);
        printf("%s\n", argv[1]);
        // for (int i = 'A'; i <= 'z'; i++)
        // {
        //     printf("%c\n", i);
        //     if (i == 'Z')
        //     {
        //         i = 'a' - 1;
        //     }
        // }
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
}

void prev(char *current[6])
{
    char ch[] = *current;
    // char ch[] = current;
    printf("%s\n", ch);
    // int len = strlen(ch);
    int len = sizeof(ch) / sizeof(char);
    ch[len - 1] = 'y';
    printf("%s\n", ch);
}

void next(string current)
{
    string *curr = &current;
    int len = strlen(*curr);
    for (int i = 0; i < len; i++)
    {
        printf("%c\n", *curr[i]);
        if (*curr[i] != 'z')
        {
            if (*curr[i] == 'Z')
            {
                *curr[i] = 'a';
            }
            else
            {
                // int ii = *atoi(&*curr[i]) + 1;
                int wo = *curr[i] + 1;
                printf("%i - %i\n", *curr[i], wo);
                // *curr[i] = atoi(*current[i]) + 1;
                // **curr[i] = wo;
                *curr[i] = wo;
            }
            // return *curr;
        }
        else if (i == len - 1)
        {
            // int nextlen = len + 1;
            // char allA[nextlen];
            for (int j = 0; j < len; j++)
            {
                // allA[j] = 'A';
                *curr[j] = 'A';
            }
            // return strcat(*curr, "A");
            *curr = strcat(*curr, "A");
        }
        // else {
        //     continue;
        // }
    }
    // return current;
}
