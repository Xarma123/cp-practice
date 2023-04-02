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
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i >= a[i] - 1)
                f = true;
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}