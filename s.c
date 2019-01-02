#include<stdio.h>
void main()
{

    int a[]={5,4,3,2,1};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=1;j<5;j++)
        {
            if(a[j-1]>a[j])
            {
                int t;
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;

            }

        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d",a[i]);
    }
}
