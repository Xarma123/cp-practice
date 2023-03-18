#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol mn = 0, mx = 0;
    for (lol i = 0; i < n; i++)
    {
        lol t1 = 0, t2 = 0;
        lol b = 0;
        for (lol j = 0; j < m; j++)
        {
            lol k = j + 1;
            while (k < m && a[i][k] == a[i][j])
                k++;
            if (a[i][j] == '1')
            {
                b += (k - j);
                t1 += (k - j) / 2;
            }
            j = k - 1;
        }
        for (lol j = 0; j < m; j++)
        {
            lol k = j + 1;
            while (k < m && (a[i][k] != a[i][k - 1] || (a[i][k] == a[i][k - 1] && a[i][k] == '0')))
                k++;
            t2 += (k - j) / 2;
            j = k - 1;
        }

        mn += b - min(t1, m / 4);
        mx += b - max(m / 4 - t2, 0ll);
    }
    cout << mn << " " << mx;

    return 0;
}