#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int len = strlen(argv[1]);
        int k[len];
        for (int i = 0; i < len; i++)
        {
            char c = argv[1][i];
            if (isalpha(c))
            {
                k[i] = toupper(c) - 'A';
            }
            else
            {
                printf("Argument should contain only alphabetical character");
                return 1;
            }
        }
        string text = get_string("plaintext: ");
        for (int i = 0, j = 0; i <= strlen(text); i++)
        {
            char c = text[i];
            if (isalpha(c))
            {
                char a = isupper(c) ? 'A' : 'a';
                char key = k[j % len];
                text[i] = (c - a + key) % 26 + a;
                j++;
            }
        }
        printf("ciphertext: %s\n", text);
    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}
