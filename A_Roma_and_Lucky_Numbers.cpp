#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        lol l = 0;
        for (auto c : s)
        {
            if (c == '4' || c == '7')
                l++;
        }
        if (l <= k)
            ans++;
    }
    cout << ans;

    return 0;
}