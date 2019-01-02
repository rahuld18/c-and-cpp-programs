#include<stdio.h>

int main()
{
int t,n,a[100],i,min,j,c=0,b[100];
scanf("%d",&t);
while(t)
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {


        scanf("%d",&a[i]);
    }


        min=a[0];

         for(j=1;j<n;j++)
         {
             if(min>a[j])
             {
                 min=a[j];
             }
         }
         for(i=0;i<n;i++)
         {
             if(a[i]%min==0)
             {


             b[i]=a[i]/min;

             }
             else
                c=1;
         }
         if(c==0)
         {
             for(i=0;i<n;i++)
             {
                 printf("%d ",b[i]);
             }
         }
         else{

            for(i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
         }
printf("\n");
    t--;
}










return 0;}
