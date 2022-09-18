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
        vector<lol> a(n);
        for (lol i = 0; i < n; i++)
            a[i] = i + 1;
        lol p = 1;
        vector<vector<lol>> ans;
        for (lol i = 0; i < n; i++)
        {
            ans.push_back(a);
            if (p >= n)
                break;
            else
            {
                swap(a[p], a[0]);
                p++;
            }
        }
        cout << ans.size() << endl;
        for (auto e : ans)
        {
            for (auto j : e)
                cout << j << ' ';
            cout << endl;
        }
    }

    return 0;
}