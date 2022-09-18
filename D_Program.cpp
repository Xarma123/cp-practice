#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        lol a[n + 1] = {0};
        for (lol i = 1; i <= n; i++)
        {
            if (s[i - 1] == '+')
                a[i] = a[i - 1] + 1;
            else
                a[i] = a[i - 1] - 1;
        }
        while (m--)
        {
            lol l, r;
            cin >> l >> r;
            cout << a[n] - (a[r] - a[l - 1]) << endl;
        }
    }

    return 0;
}