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
    vector<lol> a[n];
    map<vector<lol>, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        a[i].resize(k);
        for (lol j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
        mp[a[i]]++;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        mp[a[i]]--;
        lol s = 0;
        for (lol j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            mp[a[j]]--;
           
            vector<lol> v;
            for (lol q = 0; q < k; q++)
            {
                if (a[i][q] == a[j][q])
                {
                    v.push_back(a[i][q]);
                }
                else
                {
                    if (a[i][q] != 0 && a[j][q] != 0)
                        v.push_back(0);
                    if (a[i][q] != 1 && a[j][q] != 1)
                        v.push_back(1);
                    if (a[i][q] != 2 && a[j][q] != 2)
                        v.push_back(2);
                }
            } 
            s += mp[v];
            mp[a[j]]++;
        }
        s /= 2;
        ans += s * 1ll * (s - 1) / 2ll;
        mp[a[i]]++;
    }
    cout << ans;

    return 0;
}