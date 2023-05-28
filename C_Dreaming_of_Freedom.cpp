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
        bool f = false;
        for (lol i = 1; i * 1ll * i <= n; i++)
        {
            if (n % i == 0)
            {
                lol d = i;
                if (n / d > 1 && m >= n / d)
                {
                    f = true;
                }
                d = n / d;
                if (n / d > 1 && m >= n / d)
                {
                    f = true;
                }
            }
        }
        if (f == false)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}