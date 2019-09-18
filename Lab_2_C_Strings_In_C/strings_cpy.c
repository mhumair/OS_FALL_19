#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *s1 = "Hello";
/* 
    The wrong way to copy a string because now we 
    Two variables pointing to the start of the same memory locations

    char *s2 = s1;

*/
    /*
        $man malloc for detailed info 
        or see the Github page for more info          s
    */
    char *s2 = malloc(sizeof(char) * (strlen(s1)+1));

    strcpy(s2,s1);

    printf("The value of s1 is %s\n",s1);
    printf("The value of s1 is %s\n",s2);

    /*
        Freeing the memory section 
    */

    free(s2);
    /*
        Using or Accessing the variable now could result in an undefined behaviour
        Because the address now points to nothing
    */
    //printf("The value of s1 is %s\n",s2);
}