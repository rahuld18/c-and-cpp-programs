#include<stdio.h>
int fact(int n);
int fact(int n)
{
    if(n==1||n==0)
    {
        return 1;
    }
    else{
        return n*fact(n-1);

    }
}
void main()
{
    int n,i,f;
    printf("enter number which you want to find the factorial");

scanf("%d",&n);
f=fact(n);
printf("\n%d",f);


}
