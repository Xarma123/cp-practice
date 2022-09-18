#include <iostream>
#include <queue>
using namespace std;

class stack
{

public:
    queue<lol> a;
    queue<lol> b;
    void push(lol x)
    {
        b.push(x);
        while (a.size())
        {
            b.push(a.front());
             a.pop();
        } 
        while (b.size())
        {
             a.push(b.front());
             b.pop();
        }
        
        
    } 
    lol pop()
    {
         lol y= a.front();
         a.pop();
         return y;
    }
};

int main()
{
    stack a;
    for (lol i = 0; i < 6; i++)
    {
        a.push(i);
    }
    for (lol i = 0; i < 6; i++)
    {
        cout << (a.pop()) << " ";
    }
}