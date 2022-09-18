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
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            p[i] = i + 1;
        }
        bool ans = true;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i - 1 >= 0)
            {
                if (a[i - 1] == a[i])
                {
                    swap(p[i], p[i - 1]);
                    i--;
                    continue;
                }
            }
            if (i + 1 < n)
            {
                if (a[i + 1] == a[i])
                {
                    swap(p[i], p[i + 1]);

                    continue;
                }
            }
            ans = false;
            break;
        }
        if (ans)
        {
            for (lol i = 0; i < n; i++)
            {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}