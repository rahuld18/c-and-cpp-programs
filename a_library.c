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
char author_name[20];
int quantity;

};
struct da
{
    int dd,mm,yy;
};
struct issue
{
int id;
char student[20];
//struct da *da;
//struct da *rt;

};

struct book z;
struct issue y;
struct da d;
void password();
void viewbook();
int getdata();
void add();
void mainmenu();
void search();
void issue();
int check(int i);
void edit();
void delete_book();
void exity();
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
FILE *fp,*f,*ft,*fi;


            int main()
            {
                        mainmenu();
                //password();
                return 0;
            }


void viewbook()
{
    int j;
    system("cls");
    gotoxy(3,2);
    printf("*******************************book List****************************");
 gotoxy(4,5);
  printf("\tID\tBook Name\tStudent Name\tAuthor Name\tQuantity");
  fp=fopen("Bibek.dat","rb+");

j=8;
  while(fread(&z,sizeof(z),1,fp)==1)
  {
      gotoxy(8,j);
     printf("%d",z.id);
      gotoxy(18,j);
    printf("%s",z.name);
      gotoxy(36,j);
      printf("%s",z.student_name);
      gotoxy(51,j);
      printf("%s",z.author_name);
      gotoxy(70,j);
      printf("%d",z.quantity);
      printf("\n\n");
j++;
  }
  printf("\n\npress enter for mainmenu");
  getch();
  mainmenu();
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

    gotoxy(30,19);printf("Student name:");
     fflush(stdin);
    gets(z.student_name);
     gotoxy(30,21);printf("Author name:");
     fflush(stdin);
    gets(z.author_name);
     gotoxy(30,23);printf("QUANTITY:");
     fflush(stdin);
    scanf("%d",&z.quantity);

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

            case 2:
                {
                 delete_book();
            break;
            }
            case 3:
                {
            search();
            break;
                }
            case 4:{
            issue();
            break;
            }
            case 5:
                {
            viewbook();
            break;}
            case 6:
                {
            edit();
            break;
                }
            case 7:
                {
                    exity();
                      printf("\nAPPLICATION IS CLOSED");
                      break;
                }
            default:
                  printf("\nWrong choice");

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
printf("\nEnter ur choice:=");
scanf("%d",&s);
system("cls");


fp=fopen("Bibek.dat","ab+");
if(getdata()==1)
    {
 fseek(fp,0,SEEK_END);
    fwrite(&z,sizeof(z),1,fp);
     fclose(fp);
    printf("\nThe record is succesfully inserted\n");

    printf("\nDo u want to insert more books? Thn press y or not for 'n':=");
    fflush(stdin);
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
printf("\nPassword Match\n");
mainmenu();
}
else{
    printf("\nwrong Password entered");
 password();
}

}
void search()
{ int d,p=1;
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
    fp=fopen("Bibek.dat","rb+");
    rewind(fp);

    switch(d)
    {
    case 1:
        {
            printf("\nyou have selected search by id\n");
            printf("\nEnter id=");
            fflush(stdin);
            scanf("%d",&d);
            while(fread(&z,sizeof(z),1,fp)==1)
            {


            if(z.id==d)
            {system("cls");
                printf("Book is Available\n");
                 gotoxy(5,4);
     printf("%d",z.id);
      gotoxy(5,5);
    printf("%s",z.name);
      gotoxy(5,6);
      printf("%s",z.student_name);
      gotoxy(5,7);
      printf("%s",z.author_name);
      gotoxy(5,8);
      printf("%d",z.quantity);
      printf("\n\n");p=1;

            }
            else
            {
               p=0;
            }
            }
             if(p==0)
        {
            printf("\nBook is not available\n");
        }
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
            { system("cls");
                printf("\nBook is Available\n");
                 gotoxy(5,4);
     printf("%d",z.id);
      gotoxy(5,5);
    printf("%s",z.name);
      gotoxy(5,6);
      printf("%s",z.student_name);
      gotoxy(5,7);
      printf("%s",z.author_name);
      gotoxy(5,8);
      printf("%d",z.quantity);
      printf("\n\n");
p=1;
            }
            else
            {
                p=0;
            }

        }
        if(p==0)
        {
            printf("\nBook is not available\n");
        }
        break;
        }
    default:
        printf("\nwrong choice");

    }

fclose(fp);
printf("\n\npress enter to go at mainmenu:");
getch();
mainmenu();

}

void issue()
{
    int c,t,j=5;
    char s[20];
    printf("1.Issue book\n2.view issued book\n3.search issued book\n4.Remove issued book");
    printf("\nEnter ur choice=");
    scanf("%d",&c);
    fp=fopen("Bibek.dat","rb+");

switch(c)
{
case 1:
    {
    printf("Enter id:=");
    scanf("%d",&t);
     f=fopen("issue.dat","ab+");
    rewind(fp);

 /*   while(fread(&z,sizeof(z),1,fp)==1)
        if(z.id==t)*/
            if(check(t)==1)
    {
        printf("\nBook is available\n\n");
     printf("Enter student name=");
     fflush(stdin);
          gets(s);
          y.id=t;
        strcpy(y.student,s);
          printf("\nBook is succesfully issued");

fseek(f,0,SEEK_END);
          fwrite(&y,sizeof(y),1,f);


    }
    else
    {
        printf("\nbook is not found in library\n");
    }
    break;
    }
case 2:
    {
        system("cls");
        gotoxy(2,2);
        printf("************Issued Book List**********");

     f=fopen("issue.dat","rb+");
     rewind(f);
     gotoxy(4,4); printf("ID.");
     gotoxy(15,4);printf("Student Name");
       while(fread(&y,sizeof(y),1,f)==1)
       {
            gotoxy(4,j);
     printf("%d",y.id);
      gotoxy(15,j);
    printf("%s",y.student);
      gotoxy(35,j);
       }
break;
    }
case 3:
    {

    printf("\nEnter id which you want to searching:=");
    scanf("%d",&t);
     f=fopen("issue.dat","ab+");
    rewind(f);
    while(fread(&y,sizeof(y),1,f))
    {
      if(y.id==t)
      {
          printf("\nThis id is present\n");
          printf("id=%d\n\nname=%s",y.id,y.student);

          break;
      }
      else
      {
          printf("\nThis id is not present\n");

      }
    }







break;
    }
case 4:
    {
        printf("Enter the id of that book which you want to remove from issue list\n");
        scanf("%d",&t);
         f=fopen("issue.dat","rb+");
    rewind(f);
    while(fread(&y,sizeof(y),1,f)==1)
    {
        if(y.id==t)
        {
            fi=fopen("rei.dat","wb+");
            while(fread(&y,sizeof(y),1,f)==1)
            {
                if(y.id!=t)
                {
                                fseek(fi,0,SEEK_CUR);
                fwrite(&y,sizeof(z),1,fi);
                }

            }fclose(fi);
            remove("issue.dat");
            rename("rei.dat","issue.dat");
            printf("succesfully deleted");
            break;
        }
    }


break;
    }
default:
    {
printf("wrong choice");
    }


}
fclose(fp);
fclose(f);
printf("\n\nPress enter to go at mainmenu:");
getch();
mainmenu();
}


int check(int i)
{

    rewind(fp);

    while(fread(&z,sizeof(z),1,fp)==1)
        if(z.id==i)
        return 1;
        return 0;


}
void edit()
{
    int t,c=1;
system("cls");
    gotoxy(4,3);
    printf("Which record you want to edit\n\nEnter id=");
    scanf("%d",&t);
    fp=fopen("bibek.dat","rb+");
    rewind(fp);
    while(fread(&z,sizeof(z),1,fp)==1)
    {system("cls");
    if(check(t)==1)
    {
    gotoxy(30,17);printf("Book name:");
    fflush(stdin);
    gets(z.name);
    gotoxy(30,19);printf("Student name:");
     fflush(stdin);
    gets(z.student_name);
     gotoxy(30,21);printf("Author name:");
     fflush(stdin);
    gets(z.author_name);
     gotoxy(30,23);printf("QUANTITY:");
     fflush(stdin);
    scanf("%d",&z.quantity);
    fseek(fp,ftell(fp)-sizeof(z),0);
    fwrite(&z,sizeof(z),1,fp);
    c=0;
    break;
    }



    }
    if(c==1)
        printf("Entry not found");
fclose(fp);
printf("\n\nPress enter to go at mainmenu:");
getch();
mainmenu();
}
void delete_book()
{

    system("cls");
    int d;
    char another='y',findbook;
    while(another=='y')  //infinite loop
    {
    system("cls");
    gotoxy(10,5);
    printf("Enter the Book ID to  delete:");
    scanf("%d",&d);
    fp=fopen("Bibek.dat","rb+");
    rewind(fp);
    while(fread(&z,sizeof(z),1,fp)==1)
    {
        if(z.id==d)
        {

        gotoxy(10,7);
        printf("The book record is available");
        gotoxy(10,8);
        printf("Book name is %s",z.name);
        gotoxy(10,9);
        printf("Rack No. is %d",z.id);
        findbook='t';
        }
    }
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No record is found modify the search");
        if(getch())
        mainmenu();
    }
    if(findbook=='t' )
    {
        gotoxy(10,9);
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        ft=fopen("li.dat","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&z,sizeof(z),1,fp)==1)
        {
            if(z.id!=d)
            {
            fseek(ft,0,SEEK_CUR);
            fwrite(&z,sizeof(z),1,ft); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(ft);
        fclose(fp);
        remove("Bibek.dat");
        rename("li.dat","Bibek.dat"); //copy all item from temporary file to fp except that
        fp=fopen("Bibek.dat","rb+");    //we want to delete
        if(findbook=='t')
        {
            gotoxy(10,10);
            printf("The record is sucessfully deleted");
            gotoxy(10,11);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    mainmenu();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainmenu();



   /* int i,rm,re;
    char c,f,character;
    printf("Enter id of that entry which you want to Delete:=");
    scanf("%d",&i);
    fp=fopen("Bibek.dat","rb+");
    if(check(i)==1)
    {
        printf("book is present\n");
        printf("\n\nbook name=%s\n\nauthor name=%s\n\n",z.name,z.author_name);

        f='y';


    }
    /*
    if(c=='y')
    {
        for(i=0;i<19;i++)
        {
            z.student_name[i]='10';
        z.name[i]='10';
        z.author_name[i]='10';
        }
         z.student_name[i]=0;
        z.name[i]=0;
        z.author_name[i]=0;
        z.id=(char)'10';

        z.quantity=(char)'10';

 fseek(fp,ftell(fp)-sizeof(z),0);
 fwrite(&z,sizeof(z),1,fp);

    }
    if(c=='n')
    {
        printf("\n\nyou selected no so book is not deleted");
    }
*/

/*
if(f!='y')
{
    printf("book is not found in record");
}
if(f=='y')
{
    printf("Do u want to delete this book Y or N:=");
        fflush(stdin);
       // scanf("%c",&c);
       scanf("%c",&character);
        if(character=='y')
        {
    ft=fopen("lion.dat","wb+");
    rewind(fp);
    while(fread(&z,sizeof(z),1,fp)==1)
    {
        if(z.id!=i)
        {
            fseek(ft,0,SEEK_CUR);
            fwrite(&z,sizeof(z),1,ft);

        }
    }
fclose(ft);
fclose(fp);

 rm=remove("Bibek.dat");perror("error in remove");
       re=rename("lion.dat","Bibek.dat");
       perror("error in rename");
       if(rm==0)
       {
           printf("succesfully Removed...");
       }
       else{ printf("Failed To Removed...");}
 if(re==0)
       {
           printf("\nsuccesfully rename...");
       }
       else{ printf("\nFailed To Rename...");}

fp=ft;
fp=fopen("Bibek.dat","rb+");
if(fp==NULL)
    perror("error in fp");

if(f=='y')
{
        printf("The book is succesfully deleted");}
}character=NULL;

}f='a';
printf("\n\npress enter to go at mainmenu:");
getch();
mainmenu();
fflush(stdin);

*/
}
void exity()
{ int i;
    printf("\nExiting in 5 Second");
    for(i=0;i<10;i++)
    {
    printf(".");
    late(10000);
    }
    printf("\n\n\n");
}











