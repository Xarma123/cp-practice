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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (k >= n - i)
            {
                a[i] = 2;
                k -= n - i;
            }
            else
            {
                if (k == 0)
                    a[i] = -1000;
                else
                {
                    a[i] = -(n - i - k) * 2ll + 1;
                    k = 0;
                }
            }
        }

        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}