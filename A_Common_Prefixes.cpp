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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string s = "";
        for (lol i = 0; i < 100; i++)
        {
            s += 'a';
        }
        cout << s << '\n';
        for (lol j = 0; j < n; j++)
        {
            if (s[a[j]] == 'a')
                s[a[j]] = 'b';
            else
                s[a[j]] = 'a';
            cout << s << '\n';
        }
    }
}