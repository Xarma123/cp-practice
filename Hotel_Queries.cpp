#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    set<pair<lol, lol>> x;
    for (lol i = 0; i < n; i++)
    {
        lol v;
        cin >> v;
        x.insert({v,i})
    }
}