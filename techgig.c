
#include<stdio.h>
int main()
{
	int N,l,len,i,j;
	char S[5000],mid;
	scanf("%d",&N);
	if((N>=3)&&(N<=5000))
	{
      scanf("%s",S);
      for(l=0;S[l];l++);
      len=l;
      printf("%d",l);mid=S[N/2];
      if(N==l)
      {
           if(S[0]!=S[l-1])
          {
            S[l]=S[0];
            len++;
          }
          for(i=1;i<len;i++){


          if(S[i]!=S[l-(i)])
          {
              len++;
              for(j=len;j>=i;j--)
              {
                  S[len-j+1]=S[len-j];
                  S[i]=S[l-(i)];
              }
          }


      }}
      /* l=l+1;
              for(j=l;j>=(N/2);j--)
              {
                  S[l]=S[l-1];

              }S[N/2]=mid;*/
    printf("%s",S);

	}
	return 0;
}

