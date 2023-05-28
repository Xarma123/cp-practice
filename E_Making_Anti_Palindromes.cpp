#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 != 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            vector<char> same;
            lol dif = 0;
            map<char, lol> mp;
            for (lol i = 0; i < n / 2; i++)
            {
                if (s[i] == s[n - 1 - i])
                    same.push_back(s[i]);
                else
                {
                    dif++;
                    mp[s[i]]++;
                    mp[s[n - 1 - i]]++;
                }
            }
            if (dif == n / 2)
                cout << 0 << '\n';
            else
            {

                map<char, lol> f;
                lol mx = 0;
                char mmm;
                for (auto e : same)
                {
                    f[e]++;
                    if (f[e] > mx)
                    {
                        mx = f[e];
                        mmm = e;
                    }
                }
                lol ans = ceill((long double)same.size() / 2);
                if (mx > (long long)same.size() / 2)
                {
                    ans = same.size() - mx;
                    lol v = mx - ans;
                    dif -= mp[mmm];
                    if (dif >= v)
                    {
                        ans += v;
                    }
                    else
                        ans = -1;
                }

                cout << ans << '\n';
            }
        }
    }

    return 0;
}