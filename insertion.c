#include<stdio.h>
void main()
{
    int a[]={3,7,1,0,-6};
    int i,j;
    for(i=1;i<5;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
            {
                int t;
                t=a[j];
                a[j]=a[i];
                a[i]=t;i--;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }
}
