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
        lol a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<lol, lol>> v;
        for (lol i = 0; i < n; i++)
        {
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end());
        lol s = 0;
        lol i;
        for (i = 0; i < v.size(); i++)
        {
            lol j = i + 1;
            while (j < v.size() && v[j].first == v[i].first)
                j++;

            if (v[i].first == s)
            {
                s++;
                i = j - 1;
                continue;
            }
            if (v[i].first > s + 1)
            {
                cout << "Yes\n";
                break;
            }
            else
            {

                lol l = v[i].second;
                lol r = v[j - 1].second;
                for (lol k = l; k <= r; k++)
                {
                    a[k] = s;
                }
                lol ww = s + 1;
                sort(a, a + n);
                s = 0;
                for (lol k = 0; k < n; k++)
                {
                    lol k2 = k + 1;
                    while (k2 < n && a[k2] == a[k])
                        k2++;
                    if (a[k] != s)
                        break;
                    s++;
                    k = k2 - 1;
                }
                if (s == ww)
                    cout << "Yes\n";
                else
                    cout << "No\n";
                break;
            }
        }
        if (i == v.size())
        {
            bool ans = false;
            for (i = 0; i < v.size(); i++)
            {
                lol j = i + 1;
                while (j < v.size() && v[j].first == v[i].first)
                    j++;
                if (j - i > 1)
                    ans = true;
                i = j - 1;
            }
            if (ans)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}