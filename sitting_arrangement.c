#include<stdio.h>

struct bench{
int data1,data2;

};

void main()
{
int c,m,i,j;
    struct bench b[6][3];
    printf("Enter 18 student of cs so give the interval {i.e(60 - 77=60) }=");
    scanf("%d",&c);
    printf("Enter 18 student of me so give the interval=");
    scanf("%d",&m);
   /* for(i=0;i<6;i++){
    for(j=0;j<3;j++){


    b[i][j].data1=0;
    b[i][j].data2=0;
    printf("%d %d",b[i][j].data1,b[i][j].data2);printf("   ");
    }printf("\n");}
*/


    for(i=0;i<6;i++)
        {
    for(j=0;j<3;j++)
    {
        //if(b[i][j].data2==0 && b[i+1][j].data1==0)
        if(i%2==0)
        {

            b[i][j].data1=c;
            b[i][j].data2=m;
            c++;
            m++;
        }
        else
        {

            b[i][j].data2=c;
            b[i][j].data1=m;
            c++;
            m++;
        }
    }
        }
printf("\n\n\n");
  for(i=0;i<6;i++)
        {
            printf("!");
    for(j=0;j<3;j++)
    {
        printf("\t\t%d  %d",b[i][j].data1,b[i][j].data2);printf("      ");
    }printf(" !\n!\n!");
        }


}
