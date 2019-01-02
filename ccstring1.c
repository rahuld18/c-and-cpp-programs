/* #include<stdio.h>
#include <string.h>
char* substring(char*, int, int);

void main()
{char *c;
    char s[10];
 int i;
 gets(s);
 c=substring(s,0,2);
 printf("%s",c);

}
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* substring(char*, int, int);
char* substring(char*p, int pos, int len)
{
    int *pi;
pi[]=p[pos];
}

int main()
{
   char string[100], *pointer;
   int position = 1, length = 1, temp, string_length;

   printf("Enter a string\n");
   gets(string);

   temp = string_length = strlen(string);

   printf("Substring of \"%s\" are\n", string);

   while (position <= string_length)
   {
      while (length <= temp)
      {
         pointer = substring(string, position, length);
         printf("%s\n", pointer);
         free(pointer);
         length++;
      }
      temp--;
      position++;
      length = 1;
   }

   return 0;
}
