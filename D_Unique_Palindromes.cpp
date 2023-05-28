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
        lol n, k;
        cin >> n >> k;
        lol x[k], c[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> x[i];
        }
        for (lol i = 0; i < k; i++)
        {
            cin >> c[i];
        }
        string ans;
        char p[3] = {'a', 'b', 'c'};
        lol j = 0;
        for (lol i = 0; i < 3; i++)
        {
            ans.push_back(p[j]);
            j++;
            j %= 3;
        }
        lol tot = 3;
        bool f = true;
        char qq = 'd';
        for (lol i = 0; i < k; i++)
        {
            if (c[i] < tot)
            {
                f = false;
                break;
            }
            lol r = x[i] - (c[i] - tot);
            if (r >= ans.size())
            {
                for (lol k = ans.size(); k < r; k++)
                {
                    ans.push_back(p[j]);
                    j++;
                    j %= 3;
                }
                for (lol k = r; k < x[i]; k++)
                {
                    ans.push_back(qq);
                }
                qq++;
            }
            else
            {
                f = false;
                break;
            }
            tot = c[i];
        }
        while (ans.size() < n)
        {
            ans.push_back(p[j]);
            j++;
            j %= 3;
        }
        if (f)
            cout << "YES\n"
                 << ans << '\n';
        else
            cout << "NO\n";
    }

    return 0;
}