#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);

    lol t, m;
    cin >> t >> m;
    bool used[m];
    lol c = 1;
    map<lol, pair<lol, lol>> mp;
    for (lol i = 0; i < m; i++)
    {
        used[i] = false;
    }

    while (t--)
    {
        string s;
        cin >> s;
        if (s == "alloc")
        {
            lol q;
            cin >> q;

            lol i;
            for (i = 0; i < m; i++)
            {
                lol j;
                for (j = i; j <= i + q - 1; j++)
                {
                    if (used[j])
                        break;
                }

                if (j == i + q)
                {
                    mp[c] = {i, q};
                    for (lol j = i; j <= i + q - 1; j++)
                    {
                        used[j] = true;
                    }
                    break;
                }
            }
            if (i == m)
                cout << "NULL" << '\n';
            else
            {
                cout << c << '\n';
                c++;
            }
        }
        else if (s == "erase")
        {
            lol q;
            cin >> q;
            if (mp.count(q))
            {
                lol i = mp[q].first;
                lol n = i + mp[q].second - 1;
                for (; i <= n; i++)
                {
                    used[i] = false;
                }
                mp.erase(q);
            }
            else
                cout << "ILLEGAL_ERASE_ARGUMENT" << '\n';
        }
        else
        {
            for (lol i = 0; i < m; i++)
            {
                if (!used[i])
                {
                    lol j = i + 1;
                    if (j < m)
                    {
                        while (!used[j])
                        {
                            j++;
                            if (j == m)
                                break;
                        }
                    }
                    lol q = j - i;
                    for (auto k = mp.begin(); k != mp.end(); k++)
                    {
                        if ((*k).second.first >= i)
                        {
                            (*k).second.first -= q;
                        }
                    }
                    lol k;
                    for (k = i; k + q < m; k++)
                    {
                        used[k] = used[k + q];
                    }

                    while (k < m)
                    {
                        used[k] = false;
                        k++;
                    }
                }
            }
        }
    }

    return 0;
}