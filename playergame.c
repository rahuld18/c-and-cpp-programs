#include<stdio.h>
void main()
{
int n,i,max,w;
int a[10000],b[10000],l[10000],ml[10000];
scanf("%d",&n);
if(n<=10000)
{
    for(i=0;i<n;i++)
    {
       scanf("%d %d",&a[i],&b[i]) ;
    }

    for(i=0;i<n;i++)
    {
        l[i]=a[i]-b[i];

    }
    for(i=0;i<n;i++)
    {
        if(l[i]<0)
            ml[i]=-l[i];
        else
            ml[i]=l[i];
    }




    max=ml[0];
    for(i=0;i<n;i++)
    {

            if(max<ml[i])
            {
                max=ml[i];
            }


    }
    for(i=0;i<n;i++)
    {
        if(l[i]==max || l[i]==-max)
        {
            break;
        }
    }
    if(l[i]>0)
        w=1;
    else
        w=2;
    printf("%d %d",w,max);

}


}
