#include <stdio.h>
#include <stdlib.h>
int main(int argc , char *argv[])
{
        for(int i = 0 ; i < argc ; i++)
        {
                printf("The value is %s at index %d\n",argv[i], i);
        }
        int no = atoi(argv[1]);
        int no2 = atoi(argv[2]);
        for(int i=1;i<=100;i++)
        {
            if(i % 5==0&& i % 7==0)
            {
                printf("FizzBuzz\n");
            }
            else if(i % 5==0)
            {
                printf("Fizz\n");
            }
            else if(i % 7==0)
            {
                printf("Buzz\n");
            }
            else
            {
                printf("%d\n",i);
            }
        }
        return 0;
}
