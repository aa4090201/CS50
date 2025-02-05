#include<cs50.h>
#include<stdio.h>
int main(void)
{
    // long n = 123456789012345;
    long n = get_long("Number: ");
    // printf("%ld\n",n%100/10);
    long e = 1;
    int f = 1;
    int j = 0;
    while (n / e != 0)
    {
        e *= 10;
        j++;
        f = j;
    }
    int x = length(n);
    printf("%i",x);
    if (f == 13 || f== 15 || f == 16)
    {
        // printf("credit\n");
        long check = 10;
        long total = 0;
        // total+=n%check;
        // int total = 0;
        // printf("%ld\n",total);
        for (int i = 0; i < f; i++)
        {
            // printf("i = %i\n",i);
            if(i % 2 == 1)
            {
                int d = 0;
                d += ((n % check) / (check / 10)) * 2;
                if (d / 10 != 0)
                {
                    total += (d / 10) + (d % 10);
                }
                else
                {
                    total += d;
                }
            }
            else
            {
            total += (n % check) / (check / 10);
            }
            check *= 10;
            // printf("%ld\n========\n",total);
        }
        // printf("%ld\n========\n",total);
        if (total %10 == 0)
        {
            // printf("credit\n");
            e = 1;
            int head = 0;
            int head2 = 0;
            for (int k=1; k < j; k++)
            {
                if(k == j-1)
                {
                    head2 = (n / e) % 10;
                    // printf("head2 = %i\n",head2);
                }
                e *= 10;
                head = n / e;
            }
            if (head == 4)
            {
                // printf("%ld\n",n);
                printf("VISA");
            }
            else if (head ==5)
            {
                if (head2 == 1 || head2 == 2 || head2 == 3 || head2 == 4 || head2 == 5)
                {
                    // printf("%ld\n",n);
                    printf("MasterCard");
                }
            }
            else if (head == 3)
            {
                if (head2 == 4 || head2 == 7)
                {
                    // printf("%ld\n",n);
                    printf("American Express");
                }
            }
            else
            {
                printf("INVALID\n");
            }
            // printf("%i\n========\n",head);
        }
        else
        {
            printf("INVALID\n");
        }
        // printf("%ld\n",total);
    }
    else
    {
        printf("INVALID\n");
    }
    printf("\n");
    // for(int i=0;i<16;i++){
    //     long e = 1;
    //     int f = 1;
    //     int j = 0;
    //     while(n/e != 0){
    //         e *= 10;
    //         f = j;
    //         j++;
    //     }

    // printf("%i\n", f);

        // for(int j = 0;j <= i;j++){
        //         e *= 10;
        //         while(n/e != 0){
        //             f = j;

        //         };

        // }
        // printf("%ld\n",n/10**i);
}
