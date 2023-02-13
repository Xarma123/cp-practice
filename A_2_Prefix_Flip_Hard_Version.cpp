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
        lol s = 0, e = n - 1;
        vector<lol> ans;
        bool f = true;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (f && a[e] == b[i])
            {
                if (s <= e)
                    e--;
                else
                    e++;
                continue;
            }
            if (!f && a[e] != b[i])
            {
                if (s <= e)
                    e--;
                else
                    e++;
                continue;
            }
            if (a[e] != a[s])
                ans.push_back(1);
            if (s <= e)
            {
                ans.push_back(e - s + 1);
                s++;
                swap(s, e);
            }
            else
            {
                ans.push_back(s - e + 1);
                s--;
                swap(s, e);
            }
            if (f)
                f = false;
            else
                f = true;
        }
        cout << ans.size() << ' ';
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << '\n';
    }

    return 0;
}