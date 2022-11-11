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
    lol mode = 0;
    cin >> mode;
    for (lol i = 0; i < n; i++)
    {
        lol x;
        for (lol j = 0; j < m; j++)
        {
            cin >> x;
        }
    }
    cout << m * 1ll * (m - 1) / 2 << endl;
    for (lol i = m; i > 1; i--)
    {
        for (lol j = i - 1; j >= 1; j--)
        {
            if (mode == 0)
                cout << j << ' ' << i << endl;
            else
                cout << i << " " << j << endl;
        }
    }

    return 0;
}