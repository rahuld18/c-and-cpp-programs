#include<stdio.h>

int main()
{
    int t,i,n,f=0;
    scanf("%d",&t);
    while(t--)
    {
f=0;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }

        for(i=0;i<n;i++)
        {
            if(a[i]==a[n-1-i])
            {
                f=1;
                break;
            }

        }
        if(f==1)
            printf("yes\n");
        else
            printf("no\n");

    }

    return 0;
}
