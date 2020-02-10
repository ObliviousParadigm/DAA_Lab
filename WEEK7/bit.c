#include <stdio.h>
#include<math.h>
void decToBinary(int n,int no_0f_bits)
{
    
    int binaryNum[32];
    for (int j = 0; j < n; j++)
    {
        binaryNum[j] = 0;
    }
    // int no = n;

    int i = 0;
    while (n > 0)
    {


        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    int o=0;
    for (int k = 0; k < no_0f_bits-i; k++)
    {
        printf("%d",o);
    }
    
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}


int main()
{
    int no_0f_bits,n;
    printf("Enter no of bits:");
    scanf("%d", &no_0f_bits);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d",0);
    // }
    printf("\n");
    n=pow(2,(no_0f_bits))-1;
    printf("Max no with n bits:%d\n",n);
    for (int i = 0; i < n+1; i++)
    {
        decToBinary(i,no_0f_bits);
        printf(", ");
    }
    printf("\n");

    return 0;
}