#include<iostream.h>
 class student{
 protected:
     char name[30];
 public:
    void get()=0;
    void show()=0;


 };
 class be
 {
 protected:
    int p,c,m;
 public:
    void get()
    {
        cout<<"enter name";
        cin>>name;
        cout<<"enter marks of p c m";
        cin>>p>>c>>m;

    }
    void show()
    {
        cout<<p<<","<<c<<","<<m;
    }
 };
 void main()
 {
     student *s;
     be s1;
     s=&s1;
     s->get();
     s->show();



 }
