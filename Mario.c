#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // string name = get_string("What is your name? \n");
    // printf("hello,%s\n",name)
    int n = 8;
    do
    {
        n = get_int("What is number? \n");
    }
    while (1 > n || n > 8);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf(" ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        for (int j = 0; j < (n - i); j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
