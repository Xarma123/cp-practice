#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (k >= n)
        {
            cout << 2 * (n - 1) + 1 << endl;
        }
        else
        {
            lol c = k;
            multimap<lol, pair<lol, lol>> mp;
            for (lol i = 0; i < n - 1; i++)
            {
                if (s[i] == 'W' && s[i + 1] == 'L')
                {
                    i++;
                    lol st = i;
                    while (s[i] == 'L')
                    {
                        i++;
                        if (i == n)
                            break;
                    }
                    if (i < n)
                    {
                        lol end = i;
                        if (end != st)
                        {
                            mp.insert(make_pair((end - st), make_pair(st, end)));
                        }
                    }
                    i--;
                }
            }
            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                if ((*i).first <= c)
                {
                    for (lol j = (*i).second.first; j < (*i).second.second; j++)
                    {
                        s[j] = 'W';
                    }
                    c -= (*i).first;
                }
                else
                {
                    break;
                }
            }

            for (lol i = 0; i < n - 1; i++)
            {
                if (c == 0)
                    break;
                if (s[i] == 'W' && s[i + 1] == 'L')
                {
                    s[i + 1] = 'W';
                    c--;
                }
            }
            for (lol i = n - 1; i > 0; i--)
            {
                if (c == 0)
                    break;
                if (s[i] == 'W' && s[i - 1] == 'L')
                {
                    s[i - 1] = 'W';
                    c--;
                }
            }
            for (lol i = 0; i < n; i++)
            {
                if (c == 0)
                    break;
                if (s[i] == 'L')
                {
                    s[i] = 'W';
                    c--;
                }
            }

            lol score = 0;
            if (s[0] == 'W')
                score++;
            for (lol i = 1; i < n; i++)
            {
                if (s[i] == 'W')
                {
                    if (s[i - 1] == 'W')
                        score += 2;
                    else
                        score++;
                }
            }
            cout << score << endl;
        }
    }

    return 0;
}