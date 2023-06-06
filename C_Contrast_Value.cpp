#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
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
        if (n <= 1ll)
        {
            cout << n << '\n';
        }
        else
        {
            vector<lol> v;
            for (lol i = 0; i < n; i++)
            {
                lol j = i + 1;
                while (j < n && a[j] == a[i])
                    j++;
                v.push_back(a[i]);
                i = j - 1;
            }
            if (v.size() == 1)
                cout << 1 << '\n';
            else
            {
                lol ans = 2;
                for (lol i = 1; i < v.size() - 1; i++)
                {
                    if (v[i] > v[i - 1] && v[i] > v[i + 1])
                        ans++;
                    if (v[i] < v[i - 1] && v[i] < v[i + 1])
                        ans++;
                }
                cout << ans << '\n';
            }
        }
    }
}