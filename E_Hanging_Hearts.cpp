#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
void dfs(lol c)
{
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 2; i <= n; i++)
    {
        lol v;
        cin >> v;
        map[v].push_back(i);
    }
    dfs(1);
    return 0;
}