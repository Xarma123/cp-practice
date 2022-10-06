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
    string s;
    cin >> s;
    lol ans = 0;
    bool ad = false;
    bool again = false;
    bool ad2 = false;
    for (lol i = 0; i < s.size(); i++)
    {
        ans++;
        lol j = i + 1;
        while (j < n && s[j] == s[i])
            j++;
        if (j - i > 1)
            ad = true;
        if (j - i > 1 && ad)
            again = true;
        if (j - i > 2)
            ad2 = true;
        i = j - 1;
    }
    if (ad2 || again)
        ans += 2;
    else if (ad)
        ans++;

    cout << min(ans, (long long)s.size());

    return 0;
}