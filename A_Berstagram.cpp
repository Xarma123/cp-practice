#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol l[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> l[i];
    }
    map<lol, lol> ind;
    map<lol, set<lol>> ans;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        a[i] = i + 1;
        ind[i + 1] = i;
        ans[i + 1].insert(i);
    }
    for (lol i = 0; i < m; i++)
    {
        if (ind[l[i]] > 0)
        {
            lol j = ind[l[i]] - 1;
            lol k = ind[l[i]];

            ans[a[k]].insert(j);

            ans[a[j]].insert(k);

            ind[a[k]]--;
            ind[a[j]]++;
            swap(a[j], a[k]);
        }
    }
    for (auto i = ans.begin(); i != ans.end(); i++)
    {
        auto j = (*i).second.begin();
        auto k = (*i).second.rbegin();
        cout << (*j) + 1 << " " << (*k) + 1 << endl;
    }

    return 0;
}