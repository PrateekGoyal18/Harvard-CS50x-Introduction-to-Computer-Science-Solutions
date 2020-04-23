#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    // Check for key and do it's validation
    int validate[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int check;
    string key;
    do
    {
        if(argc==2)
        {
            key = argv[1];
        }

        if(strlen(key)!=26)
        {
            printf("Usage: ./substitution key and the key must contain 26 characters\n");
            return 1;
        }

        int len_key = strlen(key);
        for(int i=0; i<len_key; i++)
        {
            if(isalpha(key[i])==0)
            {
                printf("The key should have only alphabets\n");
                return 1;
            }
            else
            {
                check = (int)key[i] - 65;
                if(validate[check]==0)
                {
                    validate[check] = 1;
                }
                else if(validate[check]==1)
                {
                    printf("The key should have not have duplicate characters\n");
                    return 1;
                }
            }
        }
    }
    while(strlen(key)!=26);

    // Get text to encrypt
    string plaintext = get_string("plaintext: ");
    int len_plaintext = strlen(plaintext);

    // Encrypt the text
    char ciphertext[len_plaintext];
    int index;
    printf("ciphertext: ");
    for(int i=0; i<len_plaintext; i++)
    {
        if(isalpha(plaintext[i])!=0 && isupper(plaintext[i])!=0)
        {
            index = (int)plaintext[i] - 65;
            ciphertext[i] = toupper(key[index]);
        }
        else if(isalpha(plaintext[i])!=0 && islower(plaintext[i])!=0)
        {
            index = (int)plaintext[i] - 97;
            ciphertext[i] = tolower(key[index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}