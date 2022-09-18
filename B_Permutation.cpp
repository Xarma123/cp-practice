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
        set<lol> x;
        for (lol i = 1; i <= n; i++)
        {
            x.insert(i);
        }
        cout << 2 << endl;
        vector<lol> ans;
        while (!x.empty())
        {
            lol v = (*x.begin());
            while (v <= n)
            {

                if (x.count(v))
                {
                    ans.push_back(v);
                    x.erase(x.find(v));
                    v = v * 1ll * 2;
                }
                else
                    break;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}