#include<stdio.h>
#include<windows.h>

void snake();
void gotoxy(int x,int y);
COORD coord={0,0};
void gotoxy(int x,int y)
{
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void main()
{
snake();


}
void snake()
{


int i,k,l;


k=1;l=1;
    while(k<160)
    {printf("\n\n\n\n");
        for(l=0;l<k;l++)
        printf(" ");
        k++;


for(i=1;i<10;i++)
{
    if(i==9)
     printf("^>");
    else
    printf("*");
}
//scanf("%d",&k);
system("cls");

}
k=1;
l=1;
if(getch()=='u')
while(k<160)
{
    gotoxy(10,k+5);
   for(i=1;i<10;i++)
   {

        for(l=0;l<i;l++)
        printf(" ");


    if(i==9)
    printf("^>");
    else
         printf("*");

   }
system("cls");
k++;
}
}
