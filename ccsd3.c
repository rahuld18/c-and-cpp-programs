#include<stdio.h>
void main()
{

    int t,n,i,d=0,s=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];

        for(i=0;i<n;i++)
        {

            scanf("%d",&a[i]);
        }
        while(n>0){
        for(i=0;i<=a[i];i++)
        {


            if(n!=a[i])
            s=s+a[i];
        }
        n=n-s;
        d++;
        }
        printf("%d\n",d);
d=0;
    }

}
