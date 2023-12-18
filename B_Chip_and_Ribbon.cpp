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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol p[n];
        p[0] = a[0] - 1;
        for (lol i = 1; i < n; i++)
        {
            if (a[i - 1] >= a[i])
            {
                p[i] = p[i - 1];
            }
            else
            {
                p[i] = p[i - 1] + a[i] - a[i - 1];
            }
        }
        cout << p[n - 1] << '\n';
    }

    return 0;
}
