#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    set<lol> x, y;
    while (n--)
    {
        lol a, b; cin>>a>>b;
        x.insert(a);
        y.insert(b);
    }
    if (x.size() <= y.size())
    {
        cout << x.size();
    }
    else
    {
        cout << y.size();
    }

    return 0;
}