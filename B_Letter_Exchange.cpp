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
        string a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        vector<lol> trade[3][3];

        for (lol k = 0; k < n; k++)
        {
            lol f[3];
            memset(f, 0, sizeof(f));
            for (auto c : a[k])
            {
                if (c == 'w')
                    f[0]++;
                else if (c == 'i')
                    f[1]++;
                else
                    f[2]++;
            }
            for (lol i = 0; i < 3; i++)
            {
                if (f[i] == 0)
                {
                    for (lol j = i + 1; j < 3; j++)
                    {
                        if (f[j] > 1)
                        {
                            trade[i][j].push_back(k);
                            f[j]--;
                            f[i]++;
                            break;
                        }
                    }
                }
                while (f[i] > 1)
                {
                    for (lol j = i + 1; j < 3; j++)
                    {
                        if (f[j] == 0)
                        {
                            trade[j][i].push_back(k);
                            f[i]--;
                            f[j]++;
                            break;
                        }
                    }
                }
            }
        }
        string xx = "win";
        vector<string> ans;
        for (lol i = 0; i < 3; i++)
        {
            for (lol j = 0; j < 3; j++)
            {
                while (trade[i][j].size() > 0 && trade[j][i].size() > 0)
                {
                    lol a1 = trade[i][j].back() + 1;
                    trade[i][j].pop_back();
                    lol a2 = trade[j][i].back() + 1;
                    trade[j][i].pop_back();
                    string s = to_string(a1) + " ";
                    s.push_back(xx[j]);
                    s = s + " " + to_string(a2) + " ";
                    s.push_back(xx[i]);
                    ans.push_back(s);
                }
            }
        }
        for (lol i = 0; i < 3; i++)
        {
            for (lol j = 0; j < 3; j++)
            {
                for (lol k = 0; k < 3; k++)
                {
                    while (trade[i][j].size() > 0 && trade[k][i].size() > 0)
                    {
                        lol a1 = trade[i][j].back() + 1;
                        trade[i][j].pop_back();
                        lol a2 = trade[k][i].back() + 1;
                        if (k != j)
                            trade[k][j].push_back(a2 - 1);
                        trade[k][i].pop_back();
                        string s = to_string(a1) + " ";
                        s.push_back(xx[j]);
                        s = s + " " + to_string(a2) + " ";
                        s.push_back(xx[i]);
                        ans.push_back(s);
                    }
                }
            }
        }

        cout << ans.size() << '\n';
        for (auto e : ans)
            cout << e << endl;
    }

    return 0;
}