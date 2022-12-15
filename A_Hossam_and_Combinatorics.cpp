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
        sort(a, a + n);
        lol i = 0;
        while (i < n && a[i] == a[0])
            i++;
        if (i == n)
        {
            cout << n * 1ll * (n - 1) << endl;
        }
        else
        {
            lol j = n - 1;
            while (a[j] == a[n - 1])
                j--;
            cout << (i)*1ll * (n - j - 1) * 2ll << endl;
        }
    }

    return 0;
}