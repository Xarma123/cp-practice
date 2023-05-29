#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;

        set<string> x;

        for (lol i = 0; i + 1 < n; i++)
        {
            x.insert(s.substr(i, 2));
        }
        cout << x.size() << '\n';
    }
}