#include <stdio.h>
int main()
{
   char c;
   while ((c = getchar()) != EOF)
       if (c != '\n') putchar(c-7);
           else putchar(c);
   return 0;
}
