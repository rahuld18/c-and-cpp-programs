#include<stdio.h>

int main()
{int n,t,r,s;
scanf("%d",&t);
while(t)
{
    scanf("%d",&n);
    s=0;
   while(n)
   {
       r=n%10;
       s=s*10+r;

       n=n/10;
   }
   printf("%d\n",s);

    t--;
}

return 0;}
