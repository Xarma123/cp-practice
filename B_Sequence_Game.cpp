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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<lol> ans;
        ans.push_back(a[0]);
        for (lol i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1])
            {
                ans.push_back(a[i]);
            }
            else
            {
                ans.push_back(1);
                ans.push_back(a[i]);
            }
        }
        cout << ans.size() << '\n';
        for (auto e : ans)
            cout << e << " ";
        cout << '\n';
    }
}