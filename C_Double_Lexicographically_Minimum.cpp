#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol f[26];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < s.size(); i++)
        {
            f[s[i] - 'a']++;
        }
        lol i = 0, j = s.size() - 1;
        for (lol k = 0; k < 26; k++)
        {
            if (f[k])
            {
                while (f[k] >= 2ll)
                {
                    s[i] = char('a' + k);
                    i++;
                    s[j] = char('a' + k);
                    j--;
                    f[k] -= 2;
                }
                if (f[k])
                {
                    if (j - i + 1 == 1)
                    {
                        s[i] = char('a' + k);
                    }
                    else
                    {
                        lol k1;
                        for (k1 = k + 1; k1 < 26; k1++)
                        {
                            if (f[k1])
                            {
                                break;
                            }
                        }
                        if (j - i + 1 == f[k1] + 1)
                        {
                            while (f[k1] >= 2ll)
                            {
                                s[i] = char('a' + k1);
                                i++;
                                s[j] = char('a' + k1);
                                j--;
                                f[k1] -= 2;
                            }
                            if (i == j)
                            {
                                s[i] = char('a' + k);
                            }
                            else
                            {
                                s[i] = char('a' + k1);
                                s[j] = char('a' + k);
                            }
                        }
                        else
                        {
                            s[j] = char('a' + k);
                            s[i] = char('a' + k1);
                            f[k1]--;

                            i++;
                            while (i < j)
                            {
                                if (f[k1] > 0)
                                {
                                    s[i] = char('a' + k1);
                                    i++;
                                    f[k1]--;
                                }
                                else
                                    k1++;
                            }
                        }
                    }
                    break;
                }
            }
        }

        cout << s << '\n';
    }
}