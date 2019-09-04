#include <stdio.h>
#include <stdlib.h>
void swap(int*,int*);
/*
 * The swap functions makes use of the ability of pointers
 * to manipulate data even outside the variable's initial scope
 */
int main(int argc, char *argv[])
{
    printf("The no of Arguments are %d\n",argc);
    int no1 = atoi(argv[1]);
    int no2 = atoi(argv[2]);
    
    printf("THe value was %d\n",no1);
    printf("THe value was %d\n",no2);
    
    swap(&no1,&no2);
    
    printf("THe value is %d\n",no1);
    printf("THe value is %d\n",no2);
}
void swap(int *no1, int *no2)
{
        int temp = *no1;
        *no1 =*no2;
        *no2=temp;
}

