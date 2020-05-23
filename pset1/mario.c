#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter the height: ");
    }
    while(n<1 || n>8);

    // Pattern Starting
    for(int i=1; i<=n; i++)
    {
        // Spaces
        for(int j=0; j<n-i; j++)
        {
            printf(" ");
        }

        // Left hashes
        for(int j=0; j<i; j++)
        {
            printf("#");
        }

        // Gap
        printf(" ");

        // Right hashes
        for(int j=0; j<i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
