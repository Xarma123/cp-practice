#include <iostream>
#include <vector>
using namespace std; 
template<typename T>
class stack
{
private:
public: 
       vector<T> v;
      void push(T data)
      {
          v.push_back(data);
      } 

      void top()
      {
          cout<<v[v.size()-1] ;
      } 
      void pop()
      {
          v.erase(v.end()-1);
      }
};

int main()
{ 
   stack<char> a;
   a.push('a'); 
    a.push('b'); 
     a.push('c'); 
   a.top();
   a.pop();
   a.top();
}