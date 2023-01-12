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
    vector<lol> v;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] > a[j - 1])
        {
            j++;
        }
        ans = max(ans, j - i);
        v.push_back(j - i);
        i = j - 1;
    }


    lol l = -1;
    for (lol i = 0; i < v.size() - 1; i++)
    {
        lol lf = v[i];
        lol r = v[i + 1];
        lol j = lf + l;
        lol j2 = j + 1;
        bool f = false;
        if (lf > 1 && a[j2] - a[j - 1] >= 2)
            f = true;
        else if (lf == 1)
            f = true;
        else
        {
            ans = max(ans, lf + 1);
        }
        if (r > 1 && a[j2 + 1] - a[j] >= 2)
            f = true;
        else if (r == 1)
            f = true;
        else
            ans = max(ans, r + 1);
        if (f)
            ans = max(ans, lf + r);
        l += lf;
    }

    cout << ans;

    return 0;
}