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
    pair<lol, lol> row[n], col[m];
    for (lol i = 0; i < n; i++)
    {
        row[i] = {0ll, 0ll};
    }
    for (lol j = 0; j < m; j++)
    {
        col[j] = {0ll, 0ll};
    }

    lol c = 1;
    while (k--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol r;
            cin >> r;
            r--;
            lol a;
            cin >> a;
            row[r] = {c, a};
        }
        else
        {
            lol cl;
            cin >> cl;
            cl--;
            lol a;
            cin >> a;
            col[cl] = {c, a};
        }
        c++;
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (row[i].first > col[j].first)
                cout << row[i].second << " ";
            else
                cout << col[j].second << " ";
        }
        cout << endl;
    }

    return 0;
}