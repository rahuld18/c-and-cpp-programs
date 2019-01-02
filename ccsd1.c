#include<stdio.h>
int main()
{
    int t,i,n,k,c=0;
    scanf("%d",&t);
    while(t--)
    {
c=0;

        scanf("%d %d",&n,&k);
        int a[n];
        for(i=0;i<n;i++)
        {

        scanf("%d",&a[i]);

        }
        for(i=0;i<n;i++)
        {

        if(a[k]<=a[i])
            {


            c++;
        }

        }if(t==0)
        {

            c--;
        }
        printf("%d",c);
    }
    return 0;

}
