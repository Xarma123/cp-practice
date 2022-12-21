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

        sort(a + 1, a + n);
        for (lol i = 1; i < n; i++)
        {
            if (a[i] > a[0])
            {
                lol d = a[i] - a[0];
                a[0] += d / 2 + (d % 2);
            }
        }
        cout << a[0] << endl;
    }

    return 0;
}