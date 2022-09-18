#include <bits/stdc++.h>
#define lol long long
using namespace std;
// n workers  m task

bool check(vector<lol> &w, lol time, lol m)
{
    lol tasks = 0;
    for (lol i = 0; i < w.size(); i++)
    {
        if (time <= w[i])
        {
            tasks += time;
        }
        else
        {
            tasks += w[i];
            tasks += (time - w[i]) / 2;
        }
    }
    return tasks >= m;
}
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
        vector<lol> w(n, 0);
        for (lol i = 0; i < m; i++)
        {
            lol q;
            cin >> q;
            w[q - 1]++;
        }
        lol s = 0;
        lol e = INT_MAX;
        while (s != e - 1)
        {
            lol md = (s + e) / 2;
            if (check(w, md, m))
            {
                e = md;
            }
            else
                s = md;
        }
        cout << e << '\n';
    }

    return 0;
}