#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
void main()
{int i;
    for(i=0;i<50;i++)
    {
printf("*");
delay(100);
    }

/*
clock_t start, end;
double cpu_time_used;
start=clock();
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("%lf\n%f",cpu_time_used,start);
*/}
