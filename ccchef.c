#include<stdio.h>

int main()
{
int t,a,b;
scanf("%d",&t);
while(t)
{
    scanf("%d %d",&a,&b);
    if(a>b)
        printf("%d ",a);
    else
        printf("%d ",b);

    printf("%d",a+b);
    t--;
}

return 0;}
