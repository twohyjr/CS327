#include<stdio.h>

int main()
{
    int i;
    int j;
    int n;
    int prime;
    
    while (n != 0) {
        //Uses a scanner to read in an input from the user
        printf("\nFind prime numbers between 2 to n.\nEnter 0 to Exit:\n");
        scanf("%d", &n);
    
        //Uses 2 for loops to iterate through each number checking it against other numbers
        for(i = 2; i <= n; i++)
        {
            prime = 1;
            for(j = 2; j <= i/2; j++)
            {
                if(i%j==0)
                {
                    prime = 0;
                    break;      //breaks if a prime number is found
                }
            }
            if(prime == 1)
            {
                printf("%d\n", i);   //If a prime is found it prints with this line
            }
        }
    }
    
    return 0;
}