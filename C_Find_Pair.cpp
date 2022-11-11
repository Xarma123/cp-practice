#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<pair<lol, lol>> v;
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] == a[i])
            j++;
        v.push_back({a[i], j - i});
        s += j - i;
        i = j - 1;
    }
    lol p = 0;
    for (lol i = 0; i < v.size(); i++)
    {
        if (p + v[i].second * 1ll * s >= k)
        {
            k -= p;
            for (lol j = 0; j < v.size(); j++)
            {
                k -= v[i].second * 1ll * v[j].second;
                if (k <= 0)
                {
                    cout << v[i].first << " " << v[j].first;
                    break;
                }
            }

            break;
        }
        else
        {
            p += v[i].second * 1ll * s;
        }
    }

    return 0;
}