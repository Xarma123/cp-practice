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
        lol n;
        cin >> n;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << (a[0][0] == '1') << '\n';
            continue;
        }
        lol ans = 0;
        for (lol j = 0; j < n; j++)
        {
            vector<lol> in;
            for (lol i = 0; i < n; i++)
            {
                if (a[i][j] == '1')
                    in.push_back(i);
            }
            if (in.size() == 0)
                continue;
            for (lol i = 0; i < in.size() - 1; i += 2)
            {
                int v = in[i + 1] - in[i];
                int d = 1;
                if (j - 1 >= 0)
                    d++;
                if (j + 1 < n)
                    d++;
                d++;
                ans += v * 1ll * (d);
                if (in[i + 1] + 1 >= n)
                    ans--;
            }
            if (in.size() % 2)
            {
                if (in.back() == n - 1)
                {
                    ans++;
                }
                else
                {
                    int v = n - 1 - in.back();
                    int d = 1;
                    if (j - 1 >= 0)
                        d++;
                    if (j + 1 < n)
                        d++;
                    d++;
                    ans += v * 1ll * (d);
                }
            }
        }
        cout << ans << '\n';
    }
}