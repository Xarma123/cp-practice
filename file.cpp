#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n], b[m];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<lol> cary(max(n, m), 0);
    vector<lol> ans(max(n, m), 0);
    for (lol i = 0; i < cary.size(); i++)
    {

        while (ans.size() < cary.size())
            ans.push_back(0);
        lol v = cary[i];
        if (i < n)
            v += a[i];
        if (i < m)
            v += b[i];
        if (v < 0)
        {
            ans[i] = 1;
            while (cary.size() < i + 2)
                cary.push_back(0);
            cary[i + 1]++;
        }
        if (v == 0)
        {
            ans[i] = 0;
        }
        if (v == 1)
        {
            ans[i] = 1;
        }
        if (v == 2)
        {
            ans[i] = 0;
            while (cary.size() < i + 2)
                cary.push_back(0);
            cary[i + 1]--;
        }
        if (v == 3)
        {
            ans[i] = 1;
            while (cary.size() < i + 2)
                cary.push_back(0);
            cary[i + 1]--;
        }
    }
    while (ans.size() && ans.back() == 0)
    {
        ans.pop_back();
    }

    for (auto e : ans)
        cout << e << " ";

    return 0;
}
