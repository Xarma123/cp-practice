#include <iostream>
#include <stack>
using namespace std;
int main()
{
    lol n;
    stack<lol> s,ans; 
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (lol i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        } 
        ans.push(s.empty()?-1:s.top());
        s.push(a[i]);
    } 
    while (!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    
}