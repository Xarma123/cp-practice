#include <iostream>
using namespace std;
class kstack
{
public:
    lol *arr;
    lol *next;
    lol *top;
    lol freetop;
    lol cap;
    lol k;
    kstack(lol mx, lol n)
    {
        cap = mx;
        k = n;
        arr = new lol[mx];
        next = new lol[mx];
        top = new lol[n];
        freetop = 0;
        for (lol i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (lol i = 0; i < cap-1; i++)
        {
            next[i]=i+1;
        } 
        next[cap-1]=-1;
        } 
    void push(lol k,lol data)
    
       

};

int main()
{

    return 0;
}