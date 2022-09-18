#include <iostream>
#include <stack>
using namespace std; 

void insertatbottom(stack<lol> &a,lol x)
{
    if(a.empty())
   { a.push(x); 
     return;
   }
    lol t = a.top();
      a.pop();
      insertatbottom(a,x);
      a.push(t); 
      return;
}
void   rev(stack<lol> & a)
{    if(a.empty())
      return;
      lol x = a.top(); 
        a.pop();
      rev(a);
      insertatbottom(a,x);

}
int main()
{
    stack<lol> a;
    for (lol i = 1; i < 7; i++)
    {
        a.push(i);
    } 
      rev(a);
  
   
    for (lol i = 0; i < 7; i++)
    {   cout<<a.top()<<" ";
        a.pop();
       
    }
    
      
}