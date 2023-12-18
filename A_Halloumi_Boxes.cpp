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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k == 1)
        {
            bool ans = true;
            for (lol i = 1; i < n; i++)
            {
                if (a[i] < a[i - 1])
                    ans = false;
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "YES\n";
    }

    return 0;
}
