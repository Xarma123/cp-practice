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
        lol n, m, k;
        cin >> n >> m >> k;
        if (k == 1)
        {
            cout << 1 << '\n';
        }
        else if (k == 2)
        {
            if (n == 1)
                cout << m << '\n';
            else
            {
                if (m >= n)
                {
                    cout << n + (m / n) - 1 << '\n';
                }
                else
                    cout << m << '\n';
            }
        }
        else if (k == 3)
        {
            lol v = 1;
            if (n == 1)
                v += m;
            else
            {
                if (m >= n)
                {
                    v += n + (m / n) - 1;
                }
                else
                    v += m;
            }
            v = m + 1 - v;
            cout << v << '\n';
        }
        else
            cout << 0 << '\n';
    }
}