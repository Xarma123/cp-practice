#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    char c = s[0];
    lol sz = 1;
    lol ans = s[0] - 'a' + 1;
    for (lol i = 1; i < s.size() && sz < k; i++)
    {
        if (c < 'y')
        {
            if (s[i] >= c + 2)
            {
                c = s[i];
                ans += c - 'a' + 1;
                sz++;
            }
        }
    }
    if (sz < k)
        cout << -1;
    else
    {
        cout << ans;
    }
}