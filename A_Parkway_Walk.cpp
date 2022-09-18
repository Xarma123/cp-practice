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
        lol n, m;
        cin >> n >> m;
        lol ex = 0;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (lol i = 0; i < n; i++)
        {
            if (m >= a[i])
            {
                m -= a[i];
            }
            else
            {
                ex += a[i] - m;
                m = 0;
            }
        }
        cout << ex << endl;
    }

    return 0;
}