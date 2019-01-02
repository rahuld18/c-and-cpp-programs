#include<stdio.h>
int binser(int a[],int l,int h,int item);
int binser(int a[],int l,int h,int item)
{
int mid;
mid=(l+h)/2;
if(a[mid]==item)
    return mid;
else if(a[mid]>item)
    binser(a,l,mid-1,item);
else{
    binser(a,mid+1,h,item);
}
}
void main()
{
    int a[10],n;
     int item,l=0,h,m,i;
    printf("enter how many elements you want to insert");
    scanf("%d",&n);
    h=n;
    for(i=0;i<n;i++){
    printf("enter a[%d]",i);
    scanf("%d",&a[i]);

}
     printf("enter item which you want to search");
    scanf("%d",&item);


    m=binser(a,l,h,item);
    printf("\n\nitem is found at position=%d",m+1);





}
