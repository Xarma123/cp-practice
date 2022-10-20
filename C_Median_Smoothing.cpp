#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    vector<pair<lol, lol>> v;
    for (lol i = 1; i < n - 1; i++)
    {
        if (a[i] != a[i - 1] && a[i] != a[i + 1])
        {
            lol j = i + 1;
            while (j < n - 1 && a[j] != a[j - 1] && a[j] != a[j + 1])
                j++;
            v.push_back({i, j});
            ans = max(ans, (j - i) / 2 + ((j - i) % 2));
            i = j - 1;
        }
    }
    for (auto p : v)
    {
        lol l = p.first;
        lol r = p.second - 1;

        while (l <= r)
        {

            a[l] = a[l - 1];
            a[r] = a[r + 1];
            l++;
            r--;
        }
    }
    cout << ans << endl;
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}