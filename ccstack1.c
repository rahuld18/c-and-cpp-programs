#include<stdio.h>

int main()
{
    int t,i,c=0;
    char a[10];
    scanf("%d\n",&t);

    while(t){c=0;

       gets(a);
       int n=strlen(a);

        for(i=0;i<10;i++)
        {

         if(a[i]=='<')
         {

             if(a[i+1]=='>')
                c=c+2;
         }
         else if(a[i]=='>')
         {
             if(a[i-3]=='<')
                c=c+2;
         }

        }
        printf("%d\n",c);


        t--;
    }

    return 0;
}
