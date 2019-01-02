/*
#include <iostream>
   using namespace std;
   class Cat
   {
     public:
       Cat(int age):itsAge(age){count++; }
       virtual ~Cat() { count--; }
       virtual int GetAge() { return itsAge; }
       virtual void SetAge(int age) { itsAge = age; }
       static int count;
     private:
       int itsAge;
   };
   int Cat::count = 0;
   void TelepathicFunction();
   int main()
   {
     const int MaxCats = 5; int i;
     Cat *CatHouse[MaxCats];
     for (i = 0; i< MaxCats; i++)
     {
       CatHouse[i] = new Cat(i);
       TelepathicFunction();
     }
     for ( i = 0; i< MaxCats; i++)
     {
       delete CatHouse[i];
       TelepathicFunction();
     }
     return 0;
   }
   void TelepathicFunction()
   {
     cout << "There are ";
     cout << Cat::count << " cats alive!\n";
   }
   */
#include <iostream>
   using namespace std;
   class Adder
   {
     public:
       // constructor
       Adder(int i = 0)
       {
         total = i;
       }
       // interface to outside world
       void addNum(int number)
       {
         total += number;
       }
       // interface to outside world
       int getTotal()
       {
         return total;
       };
       private:
         // hidden data from outside world
         int total;
   };
   int main( )
   {
     Adder a;
     a.addNum(10);
     a.addNum(20);
     a.addNum(30);
     cout << "Total " << a.getTotal() <<endl;
     return 0;
   }
