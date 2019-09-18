#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *s1 = "OS";
    char *s2 = "OS";
/* 
    The wrong way to compare strings
    if(s1 == s2)
    {
        printf("Same\n");
    }
    else
    {
        printf("Diffrent");
    }
*/
    /*
        use this function declared in the strings.h header file
    */
    if(strcmp(s1,s2)==0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Diffrent\n");
    }
}