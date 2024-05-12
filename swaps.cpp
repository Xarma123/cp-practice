#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> lower_bound(n), upper_bound(n);
    long mx;
    for (lol i = 0; i < n; i++)
    {
        cin >> lower_bound[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> upper_bound[i];
    }
    cin >> mx;
    pair<lol, lol> a[n];
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {
        a[i] = {lower_bound[i], upper_bound[i]};
        sum += lower_bound[i];
    }
    sort(lower_bound.begin(), lower_bound.end());
    sort(upper_bound.begin(), upper_bound.end());
    sort(a, a + n);
    lol s = lower_bound[n / 2];
    lol e = upper_bound[n / 2] + 1;
    while (s != e - 1)
    {
        lol m = (s + e) / 2ll;
        if (m == upper_bound[n / 2] + 1)
        {
            e = m;
        }
        else
        {
            lol ex = 0;
            lol cnt = 0;
            for (lol i = n - 1; i >= 0; i--)
            {
                if (a[i].first >= m)
                {
                    cnt++;
                }
                else if (a[i].first <= m && a[i].second >= m)
                {
                    ex += m - a[i].first;
                    cnt++;
                }
                if (cnt == (n / 2ll) + 1)
                {
                    break;
                }
            }
            if (sum + ex <= mx)
            {
                s = m;
            }
            else
                e = m;
        }
    }
    cout << s;

    return 0;
}
