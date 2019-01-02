#include<stdio.h>
int main()
{int n,t,o=0,r;
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        while(n)
        {
            r=n%10;
            if(r==4)
                o++;
            n=n/10;


        }
        printf("%d\n",o);

o=0;

        t--;
    }


return 0;}
