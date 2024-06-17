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
        lol n, f, k;
        cin >> n >> f >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol v = a[f - 1];
        sort(a, a + n);
        if (a[n - k] < v)
        {
            cout << "YES" << '\n';
        }
        else if (a[n - k] > v)
        {
            cout << "NO\n";
        }
        else
        {
            if (n - k - 1 >= 0 && a[n - k - 1] == v)
            {
                cout << "MAYBE\n";
            }
            else
                cout << "YES\n";
        }
    }

    return 0;
}
