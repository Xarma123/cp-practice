#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, a, q;
        cin >> n >> a >> q;
        string s;
        cin >> s;
        if (a == n)
        {
            cout << "YES\n";
            continue;
        }
        lol p = 0;
        bool f = false;
        lol A = a;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
                a--;
            else
                a++, p++;
            if (a >= n)
                f = true;
        }
        if (f)
        {
            cout << "YES\n";
        }
        else if (A + p >= n)
            cout << "MAYBE\n";
        else
            cout << "NO\n";
    }
}