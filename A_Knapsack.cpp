#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, W;
        cin >> n >> W;
        pair<lol, lol> w[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> w[i].first;
            w[i].second = i + 1;
        }
        sort(w, w + n);

        lol s = 0;
        vector<lol> ans;
        for (lol j = n - 1; j >= 0; j--)
        {
            if (s >= (long long)ceill(W / (long double)2))
                break;

            if (w[j].first <= W)
            {
                s += w[j].first;
                ans.push_back(w[j].second);
            }
        }
        if (s >= (long long)ceill(W / (long double)2))
        {
            cout << ans.size() << endl;
            for (lol i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}