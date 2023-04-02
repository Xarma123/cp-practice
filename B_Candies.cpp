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
        if (n % 2 == 0)
        {
            cout << -1 << '\n';
            continue;
        }
        lol v = n;
        vector<lol> ans;
        while (v > 1)
        {
            if (((v - 1) / 2) % 2 != 0)
            {
                ans.push_back(2);
                v = ((v - 1) / 2);
            }
            else
            {
                ans.push_back(1);
                v = ((v + 1) / 2);
            }
        }
        cout << ans.size() << '\n';
        while (ans.size())
        {
            cout << ans.back() << " ";
            ans.pop_back();
        }
        cout << '\n';
    }

    return 0;
}