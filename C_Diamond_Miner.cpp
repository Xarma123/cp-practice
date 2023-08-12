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
        vector<lol> miner, gold;
        for (lol i = 0; i < 2ll * n; i++)
        {
            lol x, y;
            cin >> x >> y;
            if (x == 0)
            {
                miner.push_back(abs(y));
            }
            else
            {
                gold.push_back(abs(x));
            }
        }
        sort(miner.begin(), miner.end());
        sort(gold.begin(), gold.end());
        lol i = 0, j = miner.size() - 1;
        lol i1 = 0, j1 = gold.size() - 1;
        long double ans = 0;
        while (i <= j)
        {
            // i - j1
            lol a = miner[i] * 1ll * miner[i] + gold[j1] * 1ll * gold[j1];
            // i - i1
            lol b = miner[i] * 1ll * miner[i] + gold[i1] * 1ll * gold[i1];
            // j - j1
            lol c = miner[j] * 1ll * miner[j] + gold[j1] * 1ll * gold[j1];
            // j - i1
            lol d = miner[j] * 1ll * miner[j] + gold[i1] * 1ll * gold[i1];
            if (a <= b && a <= c && a <= d)
            {
                ans += sqrtl(a);
                i++;
                j1--;
            }
            else if (b <= a && b <= c && b <= d)
            {
                ans += sqrtl(b);
                i++;
                i1++;
            }
            else if (c <= a && c <= b && c <= d)
            {
                ans += sqrtl(c);
                j--;
                j1--;
            }
            else
            {
                ans += sqrtl(d);
                j--;
                i1++;
            }
        }
        cout << fixed << setprecision(11);
        cout << ans << '\n';
    }
}