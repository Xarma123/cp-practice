#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<lol> x;
    x.push(-1);
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && a[x.top()] > a[i])
        {
            x.pop();
            
        }
    }
}