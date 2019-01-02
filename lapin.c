#include<stdio.h>

int main(){

char s[10];
int i,j;
scanf("%s",s);

for(i=0;s[i]='\0';i++);


for(j=0;j<i;j++)
{
    if(s[j]==s[i-j])
    {
        if(i/2==j)
            {
            printf("p");
        }
    }
}

return 0;
}
