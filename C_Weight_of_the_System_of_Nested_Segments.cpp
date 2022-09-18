#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        vector<pair<lol, pair<lol, lol>>> a;
        for (lol i = 0; i < m; i++)
        {
            lol t1, t2;
            cin >> t1 >> t2;
            a.push_back(make_pair(t2, make_pair(t1, i + 1)));
        }
        sort(a.begin(), a.end());
        lol j = 2 * n;
        while (j < a.size())
        {
            a.pop_back();
        }
        lol ans = 0;
        for (lol i = 0; i < a.size(); i++)
        {
            ans += a[i].first;
            swap(a[i].first, a[i].second.first);
        }
        sort(a.begin(), a.end());
        lol i = 0;
        j = a.size() - 1;
        cout << ans << endl;
        while (i < j)
        {

            cout << a[i].second.second << " " << a[j].second.second << endl;
            i++;
            j--;
        }
    }

    return 0;
}