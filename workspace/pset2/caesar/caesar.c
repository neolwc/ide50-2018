#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int k = atoi(argv[1]);
        string text = get_string("plaintext: ");
        for (int i = strlen(text) - 1; i >= 0; i--)
        {
            printf("%i\n", i);
            char c = text[i];
            if (isalpha(c))
            {
                char a = isupper(c) ? 'A' : 'a';
                text[i] = (c - a + k) % 26 + a;
            }
        }
        printf("ciphertext: %s\n", text);
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}
