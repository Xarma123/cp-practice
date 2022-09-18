#include<iostream>
using namespace std; 
template<typename T>
class queue
{  private: 
     T *arr;
    lol f;
   lol e;
   lol ms;
   lol c;
   public:
    queue(lol ds=4)
   {
       f=0;
       
       c=0; 
       ms=ds;e=0;
       arr= new T[ms];
   }
 bool isempty()
 {
     return c==0;
 }   
 bool isfull()
 {
     return ms==c;
 } 
 void push(T x)
 {
     if(!isfull())
     {  
        arr[e]=x;
        e= (e+1)%ms; 
         c++;
     } 
 } 
 void pop()
   {
       if(!isempty())
       {
            f=(f+1)%ms;
            c--;
       }
   }
T first()
{
    return arr[f];
}
     


};
int main()
{

    queue<lol> a(7);
    for (lol i = 0; i < 8; i++)
    {
         a.push(i);
    } 
     while(!a.isempty())
    {
          cout<<a.first()<<" "; 
          a.pop();
    }
    


}