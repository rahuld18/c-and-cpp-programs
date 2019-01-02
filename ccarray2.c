#include<stdio.h>

int main()
{
    int N,C,i,r,t;
   scanf("%d",&t);
while(t){

   scanf("%d %d",&N,&C);
   int A[N];
   for(i=0;i<N;i++)
    {
   scanf("%d",&A[i]);
}
    r=C;
    for(i=0;i<N;i++)
    {
        if(A[i]<=r)
        {
            r=r-A[i];
        }else
        r=-1;

    }
    if(r>0)
        printf("Yes\n");
    else
        printf("No\n");

    t--;
}
return 0;
}
