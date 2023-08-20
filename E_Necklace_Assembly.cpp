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
        lol n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        lol f[26];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < a.size(); i++)
        {
            f[a[i] - 'a']++;
        }
        sort(f, f + 26);

        lol m;
        for (m = n; m >= 0; m--)
        {

            if (m <= 1)
            {
                break;
            }
            else
            {
                lol x[m];
                memset(x, -1, sizeof(x));
                lol c = 0;
                for (lol i = 0; i < m; i++)
                {
                    lol v;
                    if (x[i] == -1)
                    {
                        v = c++;
                    }
                    else
                        continue;
                    x[i] = v;
                    lol j = (i + k) % m;
                    while (x[j] == -1)
                    {
                        x[j] = v;
                        j += k;
                        j %= m;
                    }
                }
                sort(x, x + m);
                multiset<lol> fr;
                for (lol i = 0; i < 26; i++)
                {
                    fr.insert(f[i]);
                }

                bool fdf = true;
                vector<lol> qq;
                for (lol i = 0; i < m; i++)
                {
                    lol j = i + 1;
                    while (j < m && x[i] == x[j])
                    {
                        j++;
                    }
                    qq.push_back(j - i);
                    i = j - 1;
                }
                sort(qq.rbegin(), qq.rend());
                for (lol i = 0; i < qq.size() && fr.size(); i++)
                {
                    auto it = (*fr.rbegin());
                    if (it < qq[i])
                    {
                        fdf = false;
                        break;
                    }

                    fr.erase(fr.find(it));
                    it -= qq[i];
                    fr.insert(it);
                }
                if (fdf)
                    break;
            }
        }
        cout << m << '\n';
    }
}