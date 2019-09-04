#include <stdio.h>
#include <stdlib.h>

/* The star operator '*' is used to declare a pointer variable 
 * as well as getting the value of at an address pointed to by the pointer variable
 * 
 * The Ampersand '&' symbol is used to get the address of the variable 
 */
int main(int argc, char *argv[])
{
    int no = 55;
    //Saving an address in a pointer
    int *ptr_no = &no;
    printf("The value of no is %d\n",no);
    printf("The value of no is %d\n",*ptr_no);
    //Altering the value at the address through the pointer
    *ptr_no=100;
    printf("The value of no is %p\n",&no);
    printf("The value of no is %p\n",ptr_no);
}

