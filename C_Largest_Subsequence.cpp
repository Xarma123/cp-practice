#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
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
        bool check = true;
        for (lol i = 1; i < n; i++)
        {
            if (s[i] < s[i - 1])
            {
                check = false;
            }
        }
        if (check)
        {
            cout << 0 << '\n';
        }
        else
        {
            lol suf[n];
            suf[n - 1] = n - 1;
            for (lol i = n - 2; i >= 0; i--)
            {
                if (s[i] >= s[suf[i + 1]])
                {
                    suf[i] = i;
                }
                else
                    suf[i] = suf[i + 1];
            }
            vector<lol> ind;
            lol st = suf[0];
            while (st != n - 1)
            {
                ind.push_back(st);
                st = suf[st + 1];
            }
            ind.push_back(st);
            char c = s[ind[0]];
            lol j = 0;
            while (j < ind.size() && s[ind[j]] == c)
            {
                j++;
            }
            vector<char> v;
            for (lol i = j; i < ind.size(); i++)
            {
                v.push_back(s[ind[i]]);
            }
            reverse(v.begin(), v.end());
            for (lol i = 0; i < ind.size(); i++)
            {
                if (i < v.size())
                {
                    s[ind[i]] = v[i];
                }
                else
                    s[ind[i]] = c;
            }
            check = true;
            
            for (lol i = 1; i < n; i++)
            {
                if (s[i] < s[i - 1])
                {
                    check = false;
                }
            }
            if (check)
            {
                cout << v.size() << '\n';
            }
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}
