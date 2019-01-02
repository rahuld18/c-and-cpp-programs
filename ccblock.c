#include<stdio.h>

int main()
{
    int t,n,r,s=0,k;
scanf("%d",&t);
while(t--)
{
    s=0;
    scanf("%d",&n);
k=n;
    while(n){
    r=n%10;
    s=s*10;
    s=s+r;
    n=n/10;}

    if(s==k)
    printf("%d\nwins\n",s);
    else

    printf("%d\nlosses\n",s);

    }
    return 0;
}
