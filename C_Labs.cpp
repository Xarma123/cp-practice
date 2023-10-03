#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol g[n * 1ll * n];
    lol c = 0;
    for (lol i = 0; i < (n * 1ll * n); i++)
    {
        g[i] = c;
        c++;
        c %= n;
    }

    for (lol i = n; i < (n * 1ll * n);)
    {
        lol j = i + n - 1;
        lol q = i;
        while (i < j)
        {
            swap(g[i], g[j]);
            i++;
            
            j--;
        }
        i = q + n + n;
    }

    map<lol, vector<lol>> mp;
    for (lol i = 0; i < (n * 1ll * n); i++)
    {
        mp[g[i]].push_back(i + 1);
    }
    for (lol i = 0; i < n; i++)
    {
        for (auto e : mp[i])
            cout << e << " ";
        cout << '\n';
    }
}