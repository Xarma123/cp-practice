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
    lol a[n];
    vector<vector<lol>> seg;
    for (lol i = 0; i < m; i++)
    {
        lol l, r;
        cin >> l >> r;
        seg.push_back({r - l + 1, l, r});
    }
    sort(seg.begin(), seg.end());

    lol z = 0;
    for (lol i = seg[0][1] - 1; i < seg[0][2]; i++)
    {
        a[i] = z;
        z++;
    }
    cout << z << endl;
    lol q = 0;
    for (lol i = seg[0][2]; i < n; i++)
    {
        a[i] = q;
        q++;
        q %= z;
    }
    q = z - 1;
    for (lol i = seg[0][1] - 2; i >= 0; i--)
    {
        if (q == -1)
            q = z - 1;
        a[i] = q;
        q--;
    }
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}