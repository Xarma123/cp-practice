#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, u;
    cin >> s >> u;
    string q = u;
    for (lol i = 0; i < u.size(); i++)
    {
        q[i] = '#';
    }
    s = q + s + q;
    lol ans = u.size();
    for (lol i = 0; i + u.size() - 1 < s.size(); i++)
    {
        lol sc = 0;
        for (lol j = 0; j < u.size(); j++)
        {
            if (s[i + j] != u[j])
                sc++;
        }
        ans = min(ans, sc);
    }
    cout << ans;

    return 0;
}