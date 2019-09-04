#include <stdio.h>
#include <stdlib.h>
int main(int argc , char *argv[])
{
        for(int i = 0 ; i < argc ; i++)
        {
                printf("The value is %s at index %d\n",argv[i], i);
        }
        return 0;
}
