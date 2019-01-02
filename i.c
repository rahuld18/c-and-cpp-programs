#include<stdio.h>

void main()
{

  int i,j,temp;
  long x[1000000],y[4];
  long t,min;
  if(t<=1000000)
  {
  scanf("%ld",&t);
  for(i=0;i<t;i++)
  {
      scanf("%ld",&x[i]);
  }

  for(i=0;i<t;i++)
  {
    min=x[i];
    for(j=0;j<t;j++)
    {


    if(min>x[j])
    {
        min=x[j];
    }
    }
    y[i]=min;


  }


    for(i=0;i<t;i++)
  {
      printf("%ld\n",x[i]);
  }

}

}
