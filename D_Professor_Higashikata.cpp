#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    vector<pair<lol, lol>> v;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    while (q--)
    {
        lol v;
        cin >> v;
    }
}