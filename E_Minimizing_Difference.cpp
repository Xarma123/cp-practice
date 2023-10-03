#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol i = 0, j = n - 1;
    bool f = true;
    bool mn = true, mx = true;

    while (i < j && k > 0 && (mn || mx))
    {
       
        if (f)
        {
            if (mn)
            {
                lol op = (a[i + 1] - a[i]) * 1ll * (i + 1);
                if (op <= k)
                {
                    k -= op;
                    i++;
                }
                else
                {
                    a[i] += (k / (i + 1));
                    k -= (k / (i + 1)) * 1ll * (i + 1);
                    mn = false;
                }
            }
            f = false;
        }
        else
        {
            if (mx)
            {
                lol op = (a[j] - a[j - 1]) * 1ll * (n - j);
                if (op <= k)
                {
                    k -= op;
                    j--;
                }
                else
                {
                    a[j] -= (k / (n - j));
                    k -= (k / (n - j)) * 1ll * (n - j);
                    mx = false;
                }
            }
            f = true;
        }
    }
    cout << a[j] - a[i];
}