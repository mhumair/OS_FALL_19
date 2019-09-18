#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *s = "Hello";

    int length = 0;
    /*
        Manual way of counting the length of a string
        checking each character utill we hit the null terminator '\0'
    */
    while(s[length]!='\0')
    {
        length++;
    }
    printf("The length of the string %s is %d\n",s,length);

    printf("The length of the string %s using strlen is %ld\n",s,strlen(s));

    /*
        Note that I use %ld for strlen because strlen returns the length of type size_t

        size_t is an unsigned type. So, it cannot represent any negative values(<0). 
        You use it when you are counting something, and are sure that it cannot be negative.
        For example, strlen() returns size_t because the length of a string has to be at least 0.
    */
}