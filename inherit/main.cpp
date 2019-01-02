#include <iostream>

using namespace std;
class student{
protected: char name[30];

public:
    void get()=0;
    void show()=0;

};
/** \brief
 */
class be:public:student
{
    protected:int p,c,m;
    public:
        void get()
        {


            cout<<"enter marks";
            cin>>p>c>m
        }
};
int main()
{
    student *s;
    be s1;
    s=&s1;
    s->get();
    return 0;
}
