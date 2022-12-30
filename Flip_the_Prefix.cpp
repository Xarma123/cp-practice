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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<lol> v;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < s.size(); i++)
        {
            lol j = i + 1;
            while (j < s.size() && s[j] == s[i])
            {
                j++;
            }
            lol st = -1, e = v.size() + 1;
            
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
               
                if (m == -1)
                {
                    st = m;
                }
                else if (m == v.size() + 1)
                    e = m;
                else
                {
                    lol ans = j - i;
                    if (m < v.size())
                    {
                        ans += v.back();
                        if (m)
                            ans -= v[m - 1];
                    }
                    if (ans >= k)
                    {
                        st = m;
                    }
                    else
                        e = m;
                }
            }
            lol val = j - i;
            if (v.size())
                val += v.back();
            if (val >= k)
            {
                lol q = v.size() - st;
                if (s[i] == '0')
                    q++;
                if (st == -1)
                    q--;
                ans = min(ans, q);
            }
            if (v.size())
                v.push_back(j - i + v.back());
            else
                v.push_back(j - i);
            i = j - 1;
        }
        cout << ans << endl;
    }

    return 0;
}