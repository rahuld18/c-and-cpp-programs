       #include<stdio.h>
       void main()
       {
        long t,n;
        int i=1,z=0;
        scanf("%ld",&t);

        while(i<=t)
        {

             scanf("%ld",&n);

             z=n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625+n/1953125;
             printf("%d\n",z);



             i++;
        }

       }
