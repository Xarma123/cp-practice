#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> u(3);
    for (lol i = 0; i < 3; i++)
    {
        cin >> u[i];
    }

    sort(u.begin(), u.end());
    lol s = 0, e = u.size() + 1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2ll;
        if (m == 0)
            s = m;
        else if (m == u.size() + 1)
            e = m;
        else
        {
            cout << m << endl;
            couut << endl;
            vector<lol> dp(m);
            for (lol i = 0; i < m; i++)
            {
                dp[i] = i + 1;
            }
            for (lol i = u.size() - 1; i >= 0; i--)
            {
                lol c = u[i];
                lol j = dp.size() - 1;
                while (j >= 0 && c > 0)
                {
                    dp[j]--;
                    c--;
                    j--;
                }
                while (dp.size() > 0 && dp.back() == 0ll)
                {
                    dp.pop_back();
                }
            }
            if (dp.size() == 0)
                s = m;
            else
                e = m;
        }
    }
    cout << s << endl;
}