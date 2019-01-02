#include<stdio.h>
void main()
{
    int low=0,high,mid,item,i;
    int a[10],n;
    printf("how many elements you want to insert ?\n");
    scanf("%d",&n);
    high=n;
    for(i=0;i<high;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
printf("enter item which you want to search::-");
scanf("%d",&item);
if(low<=high){
    while(low<=high)
    {
        mid=(low+high)/2;
        if(item==a[mid])
        {
            printf("item is found");
            break;

        }
        else if(item<a[mid])
        {
            high=mid-1;

        }
        else
        {
            low=mid+1;

        }
    }
}
else{

    printf("item is not found");
}
}
