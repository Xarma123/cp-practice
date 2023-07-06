#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol pw[5] = {1, 10, 100, 1000, 10000};
        string s;
        cin >> s;
        lol pr[s.size()][5];
        memset(pr, 0, sizeof(pr));
        for (int i = 0; i < s.size(); i++)
        {
            pr[i][s[i] - 'A'] = 1;
            if (i)
            {
                for (lol j = 0; j < 5ll; j++)
                {
                    pr[i][j] += pr[i - 1][j];
                }
            }
        }
        lol suf[s.size()][5];
        memset(suf, 0, sizeof(suf));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            suf[i][s[i] - 'A'] = 1;
            if (i < s.size() - 1)
            {
                for (lol j = 0; j < 5ll; j++)
                {
                    suf[i][j] += suf[i + 1][j];
                }
            }
        }

        lol wow[s.size()][5];
        memset(wow, 0, sizeof(wow));
        for (lol i = 1; i < s.size(); i++)
        {
            if (i == 1)
            {
                wow[i][s[i - 1] - 'A'] = pw[s[i - 1] - 'A'];
                for (lol k = 3; k >= 0; k--)
                {
                    wow[i][k] += wow[i][k + 1];
                }
            }
            else
            {

                for (lol k = 0; k < (s[i - 1] - 'A'); k++)
                {
                    wow[i][k] -= pr[i - 2][k] * 1ll * pw[k];
                }
                for (lol k = (s[i - 1] - 'A'); k < 5ll; k++)
                {
                    wow[i][k] += wow[i - 1][k];
                }
                for (lol k = (s[i - 1] - 'A') - 1; k >= 0; k--)
                {
                    wow[i][k] += wow[i][k + 1];
                }
                for (lol k = 0; k <= (s[i - 1] - 'A'); k++)
                {
                    wow[i][k] += pw[s[i - 1] - 'A'];
                }
            }
        }
        lol wow2[s.size()];
        char mx = 'A';
        for (lol i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] >= mx)
            {
                wow2[i] = pw[s[i] - 'A'];
            }
            else
                wow2[i] = -pw[s[i] - 'A'];
            if (i + 1 < s.size())
                wow2[i] += wow2[i + 1];
            mx = max(mx, s[i]);
        }

        lol ans = LONG_LONG_MIN;
        for (lol j = 0; j < 5ll; j++)
        {
            for (lol i = 0; i < s.size(); i++)
            {
                lol v = 0;
                lol mxr = j;
                if (i)
                {

                    if (i + 1 < s.size())
                    {
                        for (lol k = 0; k < 5ll; k++)
                        {
                            if (suf[i + 1][k])
                                mxr = max(mxr, k);
                        }
                    }

                    for (lol k = 0; k < 5ll; k++)
                    {
                        if (k < mxr)
                        {
                            v -= pr[i - 1][k] * 1ll * pw[k];
                        }
                        else
                            break;
                    }
                    v += wow[i][mxr];
                }
                if (mxr == j)
                    v += pw[j];
                else
                    v -= pw[j];
                if (i + 1 < s.size())
                {
                    v += wow2[i + 1];
                }
                ans = max(ans, v);
            }
        }
        cout << ans << "\n";
    }
}