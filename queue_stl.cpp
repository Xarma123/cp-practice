#include <iostream>
#include <queue>
using namespace std;
int main()
{ 
    queue<lol> q;
    for (lol i = 0; i < 9; i++)
    {
         q.push(8- i);
    }
    while (!q.empty())
    {
         cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
    
}