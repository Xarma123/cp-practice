#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol v = 1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            v = v * 1ll * a[i];
        }
        if (((long long)2023) % v != 0)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            cout << "YES\n";
            v = ((long long)2023) / v;
            cout << v << " ";
            k--;
            while (k--)
            {
                cout << 1 << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
