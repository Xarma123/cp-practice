#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        vector<lol> p;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && s[j] == s[i])
                j++;
            if (s[i] == '*')
            {
                p.push_back(k * 1ll * (j - i) + 1);
            }
            i = j - 1;
        }
        reverse(p.begin(), p.end());
        lol ans[p.size()];
        x--;
        for (lol i = 0; i < p.size(); i++)
        {
            ans[i] = x % (p[i]);
            x /= p[i];
        }
        k = p.size() - 1;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                lol j = i + 1;
                while (j < n && s[j] == s[i])
                    j++;
                while (ans[k]--)
                    cout << 'b';
                k--;
                i = j - 1;
            }
            else
                cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}