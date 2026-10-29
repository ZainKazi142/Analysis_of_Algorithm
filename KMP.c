#include<stdio.h>
#include<string.h>

void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while(i<m)
    {
        if (pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }

        else
        {
            if (len!=0)
            {
                len = lps[len -1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char pattern[], char text[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0;
    int j = 0;
    int found = 0;
    
    while(i<n)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            printf("Pattern found at %d", i-j);
            found = 1;
            j = lps[j-1];
        }
        else if(i<n && pattern[j]!=text[i])
        {
            if( j!=0)
            {
                j = lps [j-1];
            }
            else
            {
                i++;
            }
        }
        
    }
    
    if(!found)
    {
        printf("Pattern not found");
    }
}

int main()
{
    char text[1000];
    char pattern[100];

    printf("Enter the text:\n");
    fgets(text,sizeof(text),stdin);

    printf("Enter the pattern:\n");
    fgets(pattern,sizeof(pattern),stdin);

    text[strcspn(text, "\n")]= "\0";
    pattern[strcspn(pattern, "\n")]= "\0";
    
    KMPSearch(pattern, text);

    return 0;
}