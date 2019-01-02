#include<stdio.h>
int min(int a[],int n,int r,int i)
{ int k,h,m;


        m=a[r];

    for( k=i;k<n;k++)
    {
        if(a[k]<m)
        {
            m=a[k];
             h=k;

        }

    }

    return h;
}
void main()
{
   int a[]={33,22,11,44,55};
   int i,j,index,n=5,r=0;
   for(i=0;i<2;i++)
   {

int y=i;
   index=min((a+i),n,r,i);
   int t;
   t=a[r];
   a[r]=a[index];
   a[index]=t;
   r++;
i=y;
   }
   for(i=0;i<5;i++)
   {
       printf("%d\t",a[i]);
   }

}
