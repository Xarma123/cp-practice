#include <bits/stdc++.h>
#define lol long long
using namespace std;
map < lol, vector<lol> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        mp.clear();
        while (k--)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        } 
        
    }

    return 0;
}