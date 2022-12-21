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
        lol n, m, k;
        cin >> n >> m >> k;
        lol a[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        if (m < k)
        {
            cout << "NO" << endl;
        }
        else
        {
            sort(a, a + m);
            if ((a[m - 1]) > n / k + (n % k > 0))
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }

    return 0;
}