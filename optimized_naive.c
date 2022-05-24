#include<stdio.h>

#include<string.h>

 void search(char pat[], char txt[])

{

    int M = strlen(pat);

    int N = strlen(txt);

    int i = 0;

 

    while (i <= N - M)

    {

        int j;

 

        /* For current index i, check for pattern match */

        for (j = 0; j < M; j++)

            if (txt[i+j] != pat[j])

                break;

 

        if (j == M)  

        {

           printf("Pattern found at index %d \n", i);

           i = i + M;

        }

        else if (j == 0)

           i = i + 1;

        else

           i = i + j;

    }

}

 

/* Driver program to test above function */

int main()

{

              char txt[20];

    char pat[10];

    printf("Enter text: ");

    gets(txt);

    printf("Enter pattern: ");

              gets(pat);

              search(pat, txt);

              return 0;

}
 

/* Driver program to test above function */


