#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long long num = 0;
    char str[16];
    do
    {
        num = get_long_long("Number: ");
    }
    while (num <= 0);

    // convert lld into a string
    sprintf(str, "%lld", num);

    int intOffset = 48;
    int len = strlen(str);

    if (len == 15 || len == 16 || len == 13)
    {
        int sum = 0;
        for (int i = len - 1, j = 1; i >= 0; i--, j++)
        {
            int step1 = str[i] - intOffset;
            int step2 = step1 * (2 - j % 2);
            int step3 = step2 % 10 + step2 / 10;
            sum += step3;
        }
        if (sum % 10 == 0)
        {
            if (str[0] == 4 + intOffset)
            {
                printf("VISA\n");
                return 0;
            }

            if (str[0] == 3 + intOffset && (str[1] == 4 + intOffset || str[1] == 7 + intOffset))
            {
                printf("AMEX\n");
                return 0;
            }

            if (str[0] == 5 + intOffset && str[1] >= 1 + intOffset && str[1] <= 5 + intOffset)
            {
                printf("MASTERCARD\n");
                return 0;
            }
        }
    }

    printf("INVALID\n");
}
