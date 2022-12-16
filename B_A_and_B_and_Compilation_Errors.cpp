#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    map<lol, lol> x;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        x[t]++;
    }
    map<lol, lol> x2;
    for (lol i = 0; i < n - 1; i++)
    {
        lol v;
        cin >> v;
        x2[v]++;
        if (--x[v] == 0)
            x.erase(v);
    }
    cout << (*x.begin()).first << endl;
    for (lol i = 0; i < n - 2; i++)
    {
        lol v;
        cin >> v;
        if (--x2[v] == 0)
            x2.erase(v);
    }
    cout << (*x2.begin()).first << endl;

    return 0;
}