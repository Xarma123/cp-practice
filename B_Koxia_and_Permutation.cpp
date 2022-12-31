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
        memset(a, -1, sizeof(a));
        lol i = k - 1;
        lol v = 1;
        while (i < n)
        {
            a[i] = v;
            v++;
            i += k;
        }
            v = n;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                a[i] = v;
                v--;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}