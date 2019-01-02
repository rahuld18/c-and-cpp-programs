#include<stdio.h>
int fact(long n);
int fact(long n)
{int f=1;
    if(n==1)
        return 1;
        else
        {
    f=f*(n-1);

        fact(n);
        return f;
        }
}
int main()
{
long t,n,c=0;
int i;
scanf("%ld",&t);
if(t<=100&&t>=1)
{
for(i=0;i<t;i++)
{
scanf("%ld",&n);

  if(n<=100&&n>=1)
  {
  c=fact(n);
  printf("%ld",c);


  }
}
}
return 0;
}
