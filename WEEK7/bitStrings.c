#include <stdio.h>
#include <math.h>
void decToBinary(int n, int no_0f_bits)
{

    int bitArray[32];
    for (int j = 0; j < n; j++)
    {
        bitArray[j] = 0;
    }

    int i = 0;
    while (n > 0)
    {
        bitArray[i] = n % 2;
        n = n / 2;
        i++;
    }

    int o = 0;
    for (int k = 0; k < no_0f_bits - i; k++)
    {
        printf("%d", o);
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", bitArray[j]);
}

int main()
{
    int no_0f_bits, n;
    printf("Enter no of bits:");
    scanf("%d", &no_0f_bits);
    n = pow(2, (no_0f_bits)) - 1;
    printf("Max number:%d\n", n);
    for (int i = 0; i < n + 1; i++)
    {
        decToBinary(i, no_0f_bits);
        if(i!=n)
        {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}