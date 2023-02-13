#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool f = true;
        for (lol i = 0; i < m & f; i++)
        {
            for (char c = 'a'; c <= 'z' & f; c++)
            {
                string b = a[0];
                b[i] = c;
                lol j;
                for (j = 0; j < n & f; j++)
                {
                    lol q = 0;
                    for (lol k = 0; k < m & f; k++)
                    {
                        if (a[j][k] != b[k])
                            q++;
                    }
                    if (q > 1)
                        break;
                }
                if (j == n)
                {
                    f = false;
                    cout << b << '\n';
                }
            }
        }
        if (f)
            cout << -1 << '\n';
    }

    return 0;
}