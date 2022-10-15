#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, p;
    cin >> n >> p;
    vector<pair<lol, lol>> r;
    for (lol i = 0; i < n; i++)
    {
        lol l, r;
        cin >> l >> r;
        r.push_back({l, r});
    }
    

    return 0;
}