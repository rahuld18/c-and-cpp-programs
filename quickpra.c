#include<stdio.h>
void swap(int ,int);
void swap(int a ,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void main()
{
int a[]={2,3,1,5,4},i=0,j=4;
int pivot=a[0];


while(i<j)
{


do
{
    i++;
}while(a[i]<pivot);
do{

    j--;
}while(a[j]>pivot);


}
}
