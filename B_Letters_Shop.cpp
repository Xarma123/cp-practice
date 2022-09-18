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
    lol fs[26][s.size()];
    for (lol i = 0; i < 26; i++)
    {
        for (lol j = 0; j < s.size(); j++)
        {
            fs[i][j] = 0;
        }
    }

    for (lol i = 0; i < s.size(); i++)
    {

        if (i != 0)
        {
            for (lol j = 0; j < 26; j++)
            {
                fs[j][i] = fs[j][i - 1];
            }
        }
        fs[s[i] - 'a'][i]++;
    }

    lol m;
    cin >> m;
    while (m--)
    {

        lol f[26];
        for (lol i = 0; i < 26; i++)
        {
            f[i] = 0;
        }

        string q;
        cin >> q;
        for (lol i = 0; i < q.size(); i++)
        {
            f[q[i] - 'a']++;
        }

        lol st = -1;
        lol e = s.size() - 1;
        while (st != e - 1)
        {
            lol m = (st + e) / 2;

            bool flag = true;
            if (m == -1)
                flag = false;
            else
            {
                for (lol i = 0; i < 26; i++)
                {
                    if (fs[i][m] < f[i])
                        flag = false;
                }
            }
            if (flag)
                e = m;
            else
                st = m;
        }
        cout << e + 1 << '\n';
    }

    return 0;
}