#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    lol ans[n];
    map<lol, vector<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ans[i] = 0;
        mp[a[i]].push_back(i);
    }
    while (k--)
    {
        lol x, y;
        cin >> x >> y;
        if (a[x - 1] > a[y - 1])
            ans[x - 1]--;
        else if (a[x - 1] < a[y - 1])
            ans[y - 1]--;
    }
    lol b = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for (lol j = 0; j < (*i).second.size(); j++)
        {
            ans[(*i).second[j]] += b;
        }
        b += (*i).second.size();
    } 
    for (lol i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    

    return 0;
}