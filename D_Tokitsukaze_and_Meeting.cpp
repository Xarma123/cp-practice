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
        lol n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        lol ansc[s.size()];
        memset(ansc, 0, sizeof(ansc));
        for (lol i = 0; i < m; i++)
        {
            lol c = 0;
            for (lol j = i; j < s.size(); j += m)
            {
                if (s[j] == '1' && c == 0)
                {
                    c = 1;
                    ansc[j] += c;
                }
            }
        }
        for (lol i = 1; i < s.size(); i++)
            ansc[i] += ansc[i - 1];
        lol l = -1;
        lol o = 0;
        lol ansr[s.size()];
        memset(ansr, 0, sizeof(ansr));
        for (lol i = 0; i < s.size(); i++)
        {
            while (i - l > m)
            {
                l++;
                if (s[l] == '1')
                    o--;
            }
            if (s[i] == '1')
                o++;
            if (o > 0)
                ansr[i]++;
        }
        for (lol i = 0; i < s.size(); i++)
        {
            if (i - m >= 0)
                ansr[i] += ansr[i - m];
        }
        for (lol i = 0; i < s.size(); i++)
            cout << ansc[i] + ansr[i] << " ";
        cout << '\n';
    }

    return 0;
}