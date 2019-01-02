#include<stdio.h>
int main(){
int t,n,k,c=0,i;

scanf("%d",&t);

while(t){
    scanf("%d %d",&n,&k);

    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
     a[i]=a[i]+k;
    }
    for(i=0;i<n;i++)
    {

        if(a[i]%7==0)
        {

            c++;
        }
    }
    printf("%d",c);


    t--;
}

}
