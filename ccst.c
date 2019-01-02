#include<stdio.h>

int main(){
    int t,i,j,n,c=0,d;
    scanf("%d",&t);

    while(t--)
    {c=0;

    scanf("%d",&n);

    char a[n];
    fflush(stdin);
    gets(a);



    for(i=0;i<n;i++)
     {

        if(a[i]=='1')
            c++;
        }

        d=(c*(c+1))/2;
printf("%d\n",d);


    }
    return 0;

}
