#include<stdio.h>
int main()
{
int w,c[100],b[100],ca=0,i,min;
scanf("%d",&w);
for( i=0;i<w;i++)
scanf("%d",&c[i]);

for( i=0;i<w;i++)
scanf("%d",&b[i]);


for( i=0;i<w;i++)
{
    if(b[i]==1)
    {

        min=c[i];
        break;
    }
}
for(i=0;i<w;i++)
{
    if(b[i]==1)
    {
        if(min>c[i])
        min=c[i];

    }



}
ca=ca+min;
for( i=0;i<w;i++)
{
    if(b[i]==2)
    {

        min=c[i];
        break;
    }
}
for(i=0;i<w;i++)
{
    if(b[i]==1)
    {
        if(min>c[i])
        min=c[i];

    }



}
ca=ca+min;
printf("%d",ca);
return 0;
}
