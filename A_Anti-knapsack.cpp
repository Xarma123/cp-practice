#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        vector<lol> ans;
        for (lol i = (k - 1) / 2 + 1; i < k; i++)
        {
            ans.push_back(i);
        }
        for (lol i = k + 1; i <= n; i++)
        {
            ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (lol i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}