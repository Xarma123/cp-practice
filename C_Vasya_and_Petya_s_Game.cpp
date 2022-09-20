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
    if (n == 1)
        cout << 0;
    else
    {
        bool p[n + 1];
        memset(p, true, sizeof(p));
        vector<lol> ans;
        for (lol i = 2; i <= n; i++)
        {
            if (p[i])
            {
                lol x = i;
                while (x <= n)
                {
                    ans.push_back(x);
                    x = x * 1ll * i;
                }
                for (lol j = i * 1ll * i; j <= n; j += i)
                {
                    p[j] = false;
                }
            }
        }
        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << " ";
    }

    return 0;
}