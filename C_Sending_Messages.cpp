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
        lol n, f, a, b;
        cin >> n >> f >> a >> b;
        lol m[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> m[i];
        }
        lol l = 0;
        for (lol i = 0; i < n; i++)
        {
            if ((m[i] - l) * 1ll * a <= b)
                f -= (m[i] - l) * 1ll * a;
            else
                f -= b;
            l = m[i];
        }
        if (f > 0)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}
