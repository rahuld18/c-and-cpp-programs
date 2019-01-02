#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
    #include<dos.h>
#include<stdlib.h>
struct book
{
int id;
char name[20];
char student_name[20];

};
struct book z;
void password();
void viewbook();
int getdata();
void add();
void mainmenu();
void search();
COORD coord={0,0};
void gotoxy(int x,int y)
{
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void late(long int n)
{
int i,j;
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
{

}
}

}

char Password[10]={"theman"};
FILE *fp,*f;


            int main()
            {
                        mainmenu();
                //password();
                return 0;
            }


void viewbook()
{int j;
    system("cls");
    gotoxy(3,2);
    printf("*******************************book List****************************");
 gotoxy(4,5);
  printf("\tID\tBook Name\tStudent Name");
  fp=fopen("lb.db","rb");

j=6;
  while(fread(&z,sizeof(z),1,fp)==1)
  {
      gotoxy(4,j);
     printf("%d",z.id);
      gotoxy(15,j);
    printf("%s",z.name);
      gotoxy(35,j);
      printf("%s",z.student_name);
      printf("\n\n");
j++;
  }
  fclose(fp);

}
int getdata()
{

    system("cls");
    gotoxy(30,15);printf("Book id:");
     fflush(stdin);
    scanf("%d",&z.id);
    gotoxy(30,17);printf("Book name:");
    fflush(stdin);
    gets(z.name);
    /*gotoxy(30,16);printf("Author name:");
    gets(b);*/
    gotoxy(30,19);printf("Student name:");
     fflush(stdin);
    gets(z.student_name);
    return 1;

}


void mainmenu()
{
    int c;
system("cls");
    printf("\t\t\t\t\tMain Menu\n\n");
       printf("\t\t\t\t\t1.ADD BOOKS\n");
          printf("\t\t\t\t\t2.DELETE BOOKS\n");
             printf("\t\t\t\t\t3.SEARCH BOOKS\n");
                printf("\t\t\t\t\t4.ISSUE BOOK\n");
                   printf("\t\t\t\t\t5.VIEW BOOK LIST\n");
                      printf("\t\t\t\t\t6.EDIT BOOK RECORD\n");
                         printf("\t\t\t\t\t7.CLOSE APPLICATION\n\n");

 printf("Enter your choice=");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {


            add();
break;


            }
            /*
            case 2:
            delete();*/
            case 3:
                {
            search();
            break;
                }
           /* case 4:
            issue();*/
            case 5:
                {


            viewbook();
            break;}
            //case 6:
            //edit_record();
            default:
            printf("APPLICATION IS CLOSED");
        }
}

void add()
{
    system("cls");
int s;
char l;
gotoxy(20,11);printf("1.Computer");
gotoxy(20,13);printf("2.Science");
gotoxy(20,15);printf("3.Electrical Engineering");
gotoxy(20,17);printf("4.Civil Engineering");
gotoxy(20,19);printf("5.Mechanical Engineering");
printf("Enter ur choice");
scanf("%d",&s);
system("cls");
z.id=0;

fp=fopen("lb.db","ab+");
if(getdata()==1)
    {
 fseek(fp,0,SEEK_END);
    fwrite(&z,sizeof(z),1,fp);
     fclose(fp);
    printf("the record is succesfully inserted");

    printf("\nDo u want to insert more books? Thn press y or not for 'n'");
    scanf("%c",&l);
    if(l=='n')
    {
    mainmenu();
    }
    else
        {
      add();
    }
}
}



void password()
{int i=0;
char  b[25]={"password protected"},pass[25],ch;
gotoxy(10,4);
    for(i=0;i<25;i++)
    {
       printf("*");
       late(5000);
    }


    for(i=0;i<b[i];i++)
    {
        printf("%c",b[i]);
        late(5000);
    }

    for(i=0;i<25;i++)
    {
        printf("*");
        late(5000);
    }

    gotoxy(15,8);
    printf("Enter password::");
    gets(pass);
/*
while(ch!='\r'&&i<20)
{
    ch=getch();
    pass[i]=ch;
    putch('*');//printf("*");
    i++;

}
pass[i]='\0';
*/
if(strcmp(Password,pass)==0)
    {
printf("Password Match");
mainmenu();
}
else
    printf("\nwrong Password entered");

}
void search()
{ int d;
char k[20];
    system("cls");
    gotoxy(4,4);
    printf("***********search Book*********");
    gotoxy(8,18);
    printf("1.Search by id");

    gotoxy(8,22);
    printf("2.Search by name");
    printf("\nenter ur choice=");
    scanf("%d",&d);
    fp=fopen("lb.db","rb+");
    rewind(fp);

    switch(d)
    {
    case 1:
        {
            printf("you have selected search by id");
            printf("\nEnter id=");
            fflush(stdin);
            scanf("%d",&d);
            if(z.id==d)
            {
                printf("Book is Available");
            }
            else
                printf("book is not Available");
            break;
        }
    case 2:
        { system("cls");

            printf("you have selected search by Name");
            printf("\nEnter Name=");
            fflush(stdin);
            gets(k);
            while(fread(&z,sizeof(z),1,fp)==1)
            {


            if(strcmp(z.student_name,(k))==0)
            {
                printf("Book is Available");
            }
            else
            {
                printf("book is not Available");
            }

        }
        break;
        }
    default:
        printf("wrong choice");

    }

fclose(fp);

}















