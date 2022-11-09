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
    vector<vector<lol>> a;
    for (lol i = 0; i < n; i++)
    {
        vector<lol> q(6, 0);
        for (lol j = 0; j < 6; j++)
        {
            cin >> q[j];
        }
        a.push_back(q);
    }

    return 0;
}