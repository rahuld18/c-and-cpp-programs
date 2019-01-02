#include <iostream>
#include<vector>

using namespace std;

int main()
{// dynamic array

    vector <int> v1 {10,20};
     vector <char> v2(4); //size 4
      vector <int> v3 (5,10);//5 size and initialize with 10
       vector <int> v4 {10,20};

    vector <string> v5 (4,"bye");
    for(int i=0;i<4;i++)
    cout<<v5[i]<<endl;                   //pushback=add element in the vector
    vector <int> v6;
    cout<<"current capacity is "<<v6.capacity()<<endl;
    v6.push_back(10);
    cout<<"now capacity is "<<v6.capacity()<<endl;
    v6.push_back(20);
    cout<<"now capacity is "<<v6.capacity()<<endl;
    v6.push_back(30);
    cout<<"now capacity is "<<v6.capacity()<<endl;
v6.pop_back();

    cout<<"now by popback capacity is "<<v6.capacity()<<endl;  //pop_back removes the element but not reduce the size
v6.pop_back();

    cout<<"now by popback capacity is "<<v6.capacity()<<endl;

    //size =no of element present
    // capacity=how much block of memory


    cout<<"now size is "<<v6.size()<<endl;
for(int i=0;i<v6.size();i++)
    cout<<endl<<v6[i]<<endl;
v6.clear();
cout<<"now size is "<<v6.size()<<endl;
cout<<"now capacity is "<<v6.capacity()<<endl;
for(int i=0;i<9;i++)
{


    v6.push_back(20*(i+1));
    cout<<v6[i]<<endl;
}

cout<<"now size is "<<v6.size()<<endl;
cout<<"now capacity is "<<v6.capacity()<<endl;
cout<<"now front is "<<v6.front()<<endl;
cout<<"now back is "<<v6.back()<<endl;
cout<<"now value at index is  "<<v6.at(0)<<endl;
vector <int>:: iterator it=v6.begin();
v6.insert(it,69);
for(int i=0;i<v6.size();i++)
{
 cout<<v6[i]<<endl;
}
    return 0;
}
