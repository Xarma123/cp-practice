#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k;
    cin >> k;
    string s;
    cin >> s;
    vector<lol> v;
    for (lol i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            v.push_back(i);
    }
    if (k)
    {
        lol ans = 0;
        for (lol i = k - 1; i < v.size(); i++)
        {
            lol j = i - k;
            if (j < 0)
            {
                lol l = v[j + 1] + 1;
                lol r;
                if (i + 1 < v.size())
                    r = v[i + 1] - v[i];
                else
                    r = s.size() - v[i];
                ans += l * 1ll * r;
            }
            else
            {
                lol l = v[j + 1] - v[j];
                lol r;
                if (i + 1 < v.size())
                    r = v[i + 1] - v[i];
                else
                    r = s.size() - v[i];
                ans += l * 1ll * r;
            }
        }
        cout << ans;
    }
    else
    {
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            lol j = i + 1;
            while (j < s.size() && s[j] == s[i])
                j++;
            if (s[i] == '0')
            {
                ans += (j - i) * 1ll * (j - i + 1) / 2ll;
            }
            i = j - 1;
        }
        cout << ans;
    }

    return 0;
}