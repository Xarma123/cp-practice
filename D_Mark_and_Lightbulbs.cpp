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
        string a, b;
        cin >> a >> b;
        if (a[0] != b[0] || a.back() != b.back())
        {
            cout << -1 << '\n';
        }
        else
        {
            vector<lol> a1;
            for (lol i = 0; i < a.size() - 1; i++)
            {
                if (a[i] != a[i + 1])
                {
                    a1.push_back(i);
                }
            }
            vector<lol> b1;
            for (lol i = 0; i < b.size() - 1; i++)
            {
                if (b[i] != b[i + 1])
                {
                    b1.push_back(i);
                }
            }
            if (b1.size() != a1.size())
            {
                cout << -1 << '\n';
            }
            else
            {
                lol ans = 0;
                for (lol i = 0; i < a1.size(); i++)
                {
                    ans += abs(a1[i] - b1[i]);
                }
                cout << ans << '\n';
            }
        }
    }

    return 0;
}