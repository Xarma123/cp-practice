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
        lol n, x;
        cin >> n >> x;
        lol h[2 * n];

        for (lol i = 0; i < 2 * n; i++)
        {
            cin >> h[i];
        }
        sort(h, h + 2 * n);
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            if (h[n + i] - h[i] < x)
            {
                f = false;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}