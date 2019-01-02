#include<stdio.h>
int main(){
int x,y,k,N,t,i,l;
scanf("%d",&t);
while(t){

    scanf("%d %d %d %d",&x,&y,&k,&N);
    int p[N],c[N];
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&p[i],&c[i]);



    }
    for(i=0;i<N;i++)
    if((x-y)<=p[i] && k>=c[i])
    {
         l=1;
        break;
    }

    if(l==1){
            printf("LuckyChef\n");

     l=0;
    }
            else
            printf("UnluckyChef\n");




    t--;
}
return 0;
}
