#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n];
    lol v[n];
    for (lol i = 0; i < n; i++)
    {
        v[i] = 0;
        cin >> a[i];
    }
    vector<vector<lol>> op;
    lol o[m];
    for (lol i = 0; i < m; i++)
    {
        o[i] = 0;
        lol l, r, d;
        cin >> l >> r >> d;
        op.push_back({l, r, d});
    }
    for (lol i = 0; i < k; i++)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        o[l]++;
        if (r < m)
            o[r]--;
    }

    for (lol i = 0; i < m; i++)
    {
        if (i > 0)
            o[i] += o[i - 1];
        op[i][2] = op[i][2] * 1ll * o[i];
        v[op[i][0] - 1] += op[i][2];
        if (op[i][1] < n)
            v[op[i][1]] -= op[i][2];
    }
    for (lol i = 0; i < n; i++)
    {
        if (i > 0)
            v[i] += v[i - 1];
        cout << a[i] + v[i] << " ";
    }

    return 0;
}