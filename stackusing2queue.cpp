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
        a.push(x); 
    } 
    lol pop()
    {
        lol n = a.size();
        for (lol i = 0; i < n - 1; i++)
        {
            lol x = a.front();
            a.push(x);
            a.pop();
        }
        lol y = a.front();
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