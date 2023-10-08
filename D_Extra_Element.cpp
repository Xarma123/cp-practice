#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    if (n == 2)
    {
        cout << 1;
    }
    else
    {
        lol d = a[1].first - a[0].first;
        lol f = -1;
        for (lol i = 1; i < n; i++)
        {
            if (a[i].first - a[i - 1].first != d)
            {
                f = i;
                break;
            }
        }
        if (f == -1 || f == n - 1)
        {
            cout << a[n - 1].second + 1;
        }
        else
        {
            if (a[f + 1].first - a[f - 1].first == d)
            {
                bool works = true;
                for (lol i = f + 2; i < n; i++)
                {
                    if (a[i].first - a[i - 1].first != d)
                    {
                        works = false;
                    }
                }
                if (works)
                {
                    cout << a[f].second + 1;
                    return 0;
                }
            }
            bool t1 = true;
            for (lol i = 2; i < n; i++)
            {
                if (a[i].first - a[i - 1].first != a[2].first - a[1].first)
                    t1 = false;
            }
            if (t1)
            {
                cout << a[0].second + 1;
                return 0;
            }
            t1 = true;
            for (lol i = 3; i < n; i++)
            {
                if (a[i].first - a[i - 1].first != a[2].first - a[0].first)
                    t1 = false;
            }

            if (t1)
            {
                cout << a[1].second + 1;
                return 0;
            }
            cout << -1;
        }
    }
}