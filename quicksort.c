#include<stdio.h>


void quick_sort(int a[],int first,int last)
{
int i,j,temp,pivot;


if(first<last)
{
pivot=first;
i=first;
j=last;


while(i<j)
{


    while(a[i]<=a[pivot]&&i<last)
        i++;
    while(a[j]>a[pivot])
        j--;

    if(i<j)
    {

        temp=a[i];
        a[i]=a[j];
        a[j]=temp;

    }
}

temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;

quick_sort(a,first,j-1);
quick_sort(a,j+1,last);


}
}


void main()
{
int a[10],i,n;
printf("Enter no of elements=:-");
scanf("%d",&n);
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
quick_sort(a,0,n-1);
printf("Sorted list is:-\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}
