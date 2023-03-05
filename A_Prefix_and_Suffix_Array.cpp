#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(string a, string b)
{
    return a.size() < b.size();
}
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
        string a[2ll * n - 2];
        for (lol i = 0; i < 2ll * n - 2; i++)
        {
            cin >> a[i];
        }
        sort(a, a + 2ll * n - 2, cmp);
        bool f = true;
        lol j = 0;
        for (lol i = 0; i < 2ll * n - 2; i += 2)
        {
            if (a[i].size() <= n / 2)
            {
                reverse(a[i].begin(), a[i].end());
                if (a[i] != a[i + 1])
                    f = false;
            }
            else
                break;
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}