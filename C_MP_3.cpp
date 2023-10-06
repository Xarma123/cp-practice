#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, I;
    cin >> n >> I;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    I = 8ll * I;
    sort(a, a + n);
    I /= n;
    if (I > 34ll)
    {
        cout << 0;
    }
    else
    {
        I = (1ll << I);
        lol ans = 0;
        vector<lol> v;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[i] == a[j])
                j++;
            v.push_back(j - i);
            i = j - 1;
        }
        if (v.size() > I)
        {
            lol p[v.size()];
            for (lol i = 0; i < v.size(); i++)
            {
                p[i] = v[i];
                if (i)
                    p[i] += p[i - 1];
            }
            ans = LONG_LONG_MAX;
            for (lol i = 0; i + I - 1 < (long long)v.size(); i++)
            {
                lol c = 0;
                if (i - 1 >= 0)
                    c += p[i - 1];
                c += p[v.size() - 1] - p[i + I - 1];
                ans = min(ans, c);
            }
        }

        cout << ans;
    }
}