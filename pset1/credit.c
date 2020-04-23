#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // Get CC Number
    long cardNum = get_long("What is your card number: ");
    long cardNum_temp = cardNum;

    // Count no. of digits
    int count = 0;
    while (cardNum_temp != 0)
    {
        cardNum_temp = cardNum_temp/10;
        count++;
    }
    // printf("%d\n", count);

    // Separate the digits
    int indivDigits[count];
    for(int i=count-1; i>=0; i--)
    {
        indivDigits[i] = cardNum%10;
        cardNum = cardNum/10;
    }

    // Starting digits
    int startNum;
    if(indivDigits[0] == 4)
    {
        startNum = 4;
    }
    else
    {
        startNum = indivDigits[0]*10 + indivDigits[1];
    }
    // printf("%d\n", startNum);

    // Checksum Calculation
    int sum1=0, sum2=0, sum, pdtBy2;
    for(int i=count-2; i>=0; i=i-2)
    {
        pdtBy2 = indivDigits[i]*2;
        if(pdtBy2>9)
        {
            sum1 = sum1 + (pdtBy2%10);
            pdtBy2 = pdtBy2/10;
            sum1 = sum1 + (pdtBy2%10);
        }
        else
        {
            sum1 = sum1 + pdtBy2;
        }
    }
    int rem_startIndex;
    if(count%2==0)
    {
        rem_startIndex = 1;
    }
    else
    {
        rem_startIndex = 0;
    }
    for(int i=rem_startIndex; i<count; i=i+2)
    {
        sum2 = sum2 + indivDigits[i];
    }
    sum = sum1 + sum2;
    // printf("%d\n", sum);

    // Final Deduction
    if(count==15 && (startNum==34||startNum==37) && sum%10==0)
    {
        printf("AMEX\n");
    }
    else if(count==16 && (startNum==51||startNum==52||startNum==53||startNum==54||startNum==55) && sum%10==0)
    {
        printf("MASTERCARD\n");
    }
    else if((count==13||count==16) && startNum==4 && sum%10==0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}