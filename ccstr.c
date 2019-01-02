#include<stdio.h>

void sub(char *p,int si,int ei,int len)
{
    char a[len];

    int i=0;
    while(si<=ei)
    {
        a[i++]=p[si++];
    }
    printf("%s",a);

}

void main()
{
    int t,n,i,si,ei,l;
    scanf("%d",&t);
    while(t--)
    {
        fflush(stdin);
        scanf("%d",&n);
        char b[n];
        gets(b);
        for(si=0;si<n;si++)
        for(ei=0;ei<n;ei++)
        {
          sub(b,si,ei,4);
        }



    }



}
