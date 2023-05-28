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
        {
            cin >> a[i];
        }
        lol i = 0, j = n - 1;
        while (i < j)
        {
            if (a[i] != a[j])
                break;
            i++;
            j--;
        }
        if (i >= j)
            cout << 0 << '\n';
        else
        {
            i = 0, j = n - 1;
            lol g = 0;
            while (i < j)
            {
                if (a[i] != a[j])
                {
                    g = __gcd(g, (long long)abs(a[i] - a[j]));
                }
                i++;
                j--;
            }
            cout << g << '\n';
        }
    }

    return 0;
}