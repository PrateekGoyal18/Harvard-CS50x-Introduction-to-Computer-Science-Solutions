#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int main(void)
{
    string str = get_string("Enter the text: ");
    int str_len = strlen(str);
    int count_l=0, count_w=0, count_s=0;

    // Calculate no. of letters, words and sentences
    for(int i=0; i<str_len; i++)
    {
        int temp = str[i];
        if(str[i]=='.' || str[i]=='!' || str[i]=='?')
        {
            count_s++;
        }
        else if(str[i]==' ')
        {
            count_w++;
        }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            count_l++;
        }
    }
    count_w++;

    float avg_lw = (count_l*100)/(float)count_w; // average number of letters per 100 words in the text
    float avg_sw = (count_s*100)/(float)count_w; // average number of sentences per 100 words in the text

    // Formula for Coleman-Liau index
    int index = round(0.0588*avg_lw - 0.296*avg_sw - 15.8);

    // US grade level needed to understand the text
    if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}