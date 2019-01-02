#include<stdio.h>

int main()
{
    int N,i,t,c=0,j=0;
   scanf("%d",&t);
while(t){

   scanf("%d",&N);
   int A[N];
   for(i=0;i<N;i++)
    {
   scanf("%d",&A[i]);
}

    for(i=0;i<N;i++)
    {

       if(A[j]!=A[j+1])
       {
          A[j]++;
          A[j+1]++;
          c++;
       }
       if(A[j]!=A[j+1])
       {


       }

    }
    printf("%d",c);
}
}
