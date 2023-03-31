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
        bool z = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                z = false;
        }
        bool ans = true;
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] == 0 && a[i] == 1)
                ans = false;
            if (b[i] == 1 && a[i] == 0 && z)
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}