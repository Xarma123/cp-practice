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
        lol f[101];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        bool ans = true;
        for (lol i = 0; i < 101; i++)
        {
            if (f[i] % 2)
                ans = false;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}