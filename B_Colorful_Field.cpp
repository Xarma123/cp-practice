#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<vector<lol>> f(n);
    while (k--)
    {
        lol a, b;
        cin >> a >> b;
        f[a - 1].push_back(b);
    }
    for (lol i = 0; i < n; i++)
    {
        sort(f[i].begin(), f[i].end());
    }
    while (t--)
    {
        lol i, j;
        cin >> i >> j;
        i--;
        lol c = 0;
        for (lol a = 0; a < i; a++)
        {
            c += m;
            c -= f[a].size();
        }
        lol ind = lower_bound(f[i].begin(), f[i].end(), j) - f[i].begin();
        if (ind < f[i].size() && f[i][ind] == j)
        {
            cout << "Waste" << endl;
        }
        else
        {
            c += j - ind;
            c %= 3;
            if (c == 1)
                cout << "Carrots" << endl;
            else if (c == 2)
                cout << "Kiwis" << endl;
            else
                cout << "Grapes" << endl;
        }
    }

    return 0;
}