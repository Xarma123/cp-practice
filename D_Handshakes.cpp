#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    set<pair<lol, lol>> v[3];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        v[a[i] % 3].insert({a[i], i});
    }
    lol ans[n];
    memset(ans, -1, sizeof(ans));
    bool f = true;
    for (lol i = 0; i < 3 && f; i++)
    {

        lol j = i;
        lol l = i;
        while (!v[i].empty())
        {
            if (j >= n)
            {
                f = false;
                break;
            }
            auto it = v[i].upper_bound({l, n});
            
            if (it == v[i].begin())
            {
                f = false;
                break;
            }
            it--;

            ans[j] = (*it).second;
            l = a[ans[j]] + 3;
            j += 3;
            v[i].erase(it);
        }
    }
    // for (lol i = 0; i < 3 && f; i++)
    // {
    //     lol l = i;
    //     for (lol j = i; j < n && f; j += 3)
    //     {
    //         if (ans[j] == -1)
    //         {
    //             f = false;
    //             break;
    //         }
    //         if (a[ans[j]] - l > 3)
    //         {
    //             f = false;
    //             break;
    //         }
    //         l = a[ans[j]];
    //     }
    // }
    // lol l = 0;
    // for (lol i = 0; i < n && f; i++)
    // {
    //     if (a[ans[i]] > l)
    //     {
    //         f = false;
    //         break;
    //     }
    //     l = a[ans[i]] + 1;
    // }

    if (!f)
        cout << "Impossible";
    else
    {
        cout << "Possible" << endl;
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] + 1 << " ";
        }
    }

    return 0;
}