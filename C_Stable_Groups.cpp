#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k, x;
    cin >> n >> k >> x;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol g = 1;
    sort(a, a + n);
    vector<lol> gap;

    for (lol i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] > x)
        {
            g++;
            gap.push_back(a[i + 1] - a[i]);
        }
    }
    sort(gap.begin(), gap.end());
    for (lol i = 0; i < gap.size(); i++)
    {
        if (k == 0)
            break;
        if (gap[i] <= 2 * x)
        {
            g--;
            k--;
        }
        else
        {
            if (gap[i] % x == 0)
            {
                lol r = gap[i] / x - 1;
                if (k >= r)
                    k -= r;
                else
                    break;
                g--;
            }
            else
            {
                lol r = gap[i] / x - 1;
                r++;
                if (k >= r)
                    k -= r;
                else
                    break;
                g--;
            }
        }
    }
    cout << g << endl;

    return 0;
}