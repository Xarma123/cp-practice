#include <iostream>
using namespace std;
class stack2
{
public:
    lol *arr;
    lol s;
    lol e;
    lol mx;
    stack2(lol n)
    {
        s = 0;
        mx = n;
        e = n - 1;
        arr = new lol[mx];
    }
    void push1(lol x)
    {
        if (s <= e)
        {
            arr[s] = x;
            s++;
        }
    }
    void push2(lol x)
    {
        if (s <= e)
        {
            arr[e] = x;
            e--;
        }
    }
    lol pop1()
    {
        lol k = s - 1;
        if(k>=0)
        {s--;
        return arr[k];}
        return -1;
    }
    lol pop2()
    {
        lol k = e+1;
        if(k<mx)
      {  e++;
         return arr[k];
      } 
      return -1;

    } 
    lol size1()
    {
        return s;
    }
    lol size2()
    {
        return mx-e-1;
    } 
    lol top1()
    {
        return arr[s-1];
    }
    lol top2()
    {
        return arr[e+1];
    }
};
int main()
{ 
    stack2 a(8);
    a.push1(1);
    a.push1(2);
    a.push1(3);
    a.push1(4);
    a.push1(5);
    a.push2(1);
    a.push2(2);
    a.push2(3);
    a.pop1();
    a.pop2();
     a.push1(5);
     a.push1(5);
     a.push1(5);
     a.push1(5);
     a.push1(5);
     a.push1(5);
     a.push1(5);
    cout<<a.top1();
    cout<<a.top2();




}