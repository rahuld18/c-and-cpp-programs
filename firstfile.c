#include<stdio.h>
void main()
{

 FILE *fp;
    int c;
    fp=fopen("lb.db","w");
    if(fp==NULL)
        printf("error");
    else
        printf("file created");
}
