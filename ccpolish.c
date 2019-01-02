#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
	    char str[500],res[500],top=0;
	    int i;
        scanf("%s",str);
        for(i=0;str[i]!='\0';i++){

            if(str[i]=='('||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
                res[top++]=str[i];
            else if(str[i]==')'){
                top--;
                while(res[top]!='(')
                    printf("%c",res[top--]);

                }
                else
                    printf("%c",str[i]);


            }
            printf("\n");
        }


	return 0;
}
