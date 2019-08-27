#include <stdio.h>

int main(int argc, char *argv[]) 
{
    printf("The total number of Arguments are %d\n",argc);
    
    for(int i=0; i < argc ; i++)
    {
            printf("The String at index %d is %s\n",argc,argv[i]);
    }
    
}
