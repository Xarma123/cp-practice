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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k == 1)
        {
            lol a = 0;
            for (lol i = 1; i < n - 1; i += 2)
            {
                a++;
            }
            lol b = 0;
            for (lol i = 2; i < n - 1; i += 2)
            {
                b++;
            }
            a = max(a, b);
            cout << a << endl;
        }
        else
        {
            lol c = 0;
            for (lol i = 1; i < n - 1; i++)
            {
                if (a[i] > a[i - 1] + a[i + 1])
                    c++;
            }
            cout << c << endl;
        }
    }

    return 0;
}