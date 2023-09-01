#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit = get_long("Number: ");
    // finding length of number
    long temp = credit;
    int length = 0;
    while (temp != 0)
    {
        temp /= 10;
        length++;
    }

    // adding all digits in a Array
    temp = credit;

    int digit[length];

    for (int i = 0; i < length; i++)
    {
        digit[i] = temp % 10;
        temp /= 10;
    }

    // doing sum of first alternate digits
    int sum1 = 0;
    for (int i = 0; i < length; i += 2)
    {
        sum1 = sum1 + digit[i];
    }

    // doing sum of twice of multiplication of alternate digit
    int sum2 = 0;
    for (int i = 1; i < length; i += 2)
    {
        int j = digit[i] * 2;
        if (j <= 9)
        {
            sum2 += j;
        }
        else
        {
            for (int k = 0; k < 2; k++)
            {
                sum2 += j % 10;
                j /= 10;
            }
        }
    }
    int check_sum = sum1 + sum2;

    // total Number and final verifaction with Output
    if (digit[12] == 4 && length == 13 && check_sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else if (digit[14] == 3 && length == 15 && check_sum % 10 == 0)
    {
        if (digit[13] == 4 || digit[13] == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digit[15] == 4 && length == 16 && check_sum % 10 == 0)
    {
        printf("VISA\n");
    }
    else if (digit[15] == 5 && length == 16 && check_sum % 10 == 0)
    {
        if (digit[14] == 1 || digit[14] == 2 || digit[14] == 3 || digit[14] == 4 || digit[14] == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
