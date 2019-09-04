#include <stdio.h>

int main(void)
{
        int no = 15;
        printf("Print a Number      : %d \n", no);
        
        float no_f=15.3333;
        printf("Print a float       : %.3f \n", no_f);
        
        char c = 'c';
        printf("Print a character   : %c    \n",'c');
        
        char s[] = "Hello World\n";
        printf("Print a String      : %s    \n", s);
        
        s[3] = 'A';
        printf("The Value is %c\n",s[3]);
        
        return 0;
}
