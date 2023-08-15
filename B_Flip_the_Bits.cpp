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
        string a, b;
        cin >> a >> b;
        bool val[n];
        memset(val, false, sizeof(val));
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == '1')
                s++;
            else
                s--;
            if (s == 0)
                val[i] = true;
        }
        bool ans = true;
        lol inv = 0;
        for (lol i = n - 1; i >= 0 && ans; i--)
        {
            if (inv)
            {
                if (a[i] == '1')
                    a[i] = '0';
                else
                    a[i] = '1';
            }
            if (a[i] != b[i])
            {
                if (val[i])
                {
                    inv++;
                    inv %= 2;
                }
                else
                    ans = false;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}