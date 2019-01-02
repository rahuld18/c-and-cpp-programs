#include<stdio.h>
struct book
{
    char bname[30];
    int bid;

};
void mainmenu()
{
    printf("\t\t\t\t\tMain Menu\n\n");
       printf("\t\t\t\t\t1.ADD BOOKS\n");
          printf("\t\t\t\t\t2.DELETE BOOKS\n");
             printf("\t\t\t\t\t3.SEARCH BOOKS\n");
                printf("\t\t\t\t\t4.ISSUE BOOK\n");
                   printf("\t\t\t\t\t5.VIEW BOOK LIST\n");
                      printf("\t\t\t\t\t6.EDIT BOOK RECORD\n");
                         printf("\t\t\t\t\t7.CLOSE APPLICATION\n\n");


}
void add()
{
    struct book b;

    FILE *fp;
    char ch;


    fp=fopen("lb.db","a");
    if(fp==NULL)
        printf("error");
    else
        printf("file created\n");

  printf("Enter details of the book\n");
  printf("Enter book name\n");
  fflush(stdin);
  gets(b.bname);
  printf("Enter book id \n");
   fflush(stdin);
  scanf("%d",&b.bid);

  fputs(b.bname,fp);
 /* while((ch=getche())!='\r')
    fputc(ch,fp);
  //fprintf(fp,"\t%d\n",b.bid);*/
  fwrite(ch,sizeof(ch),1,fp);

fclose(fp);
}
void delete()
{

}
void search()
{

}
void issue()
{

}
void book_list()
{


}
void edit_record()
{

}


void main()
{
    FILE *fp;
    struct book b;
    int c;
    fp=fopen("lb.db","w");
    if(fp==NULL)
        printf("error");
    else
        printf("file created");



mainmenu();

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
            delete();
            case 3:
            search();
            case 4:
            issue();
            case 5:
            book_list();
            case 6:
            edit_record();
            default:
            printf("APPLICATION IS CLOSED");
        }




















}
