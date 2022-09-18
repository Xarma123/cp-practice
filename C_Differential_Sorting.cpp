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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool ans = true;
        lol p = -1;
        if (a[n - 1] >= 0)
            p = n - 1;
        lol i;
        for (i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
            {
                if (p == -1 || p == i + 1)
                    ans = false;
                break;
            }
            if (a[i] >= 0 && p == -1)
                p = i;
        }
        if (!ans)
            cout << -1 << endl;
        else
        {
            if (p - 2 < 0)
                cout << 0 << endl;
            else
            {
                cout << p - 1 << endl;
                for (lol i = p - 2; i >= 0; i--)
                {
                    cout << i + 1 << " " << p << " " << p + 1 << endl;
                }
            }
        }
    }

    return 0;
}