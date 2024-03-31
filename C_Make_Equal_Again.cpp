#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
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
        lol i = 0;
        while (i < n && a[i] == a[0])
            i++;
        lol j = n - 1;
        while (j >= 0 && a[j] == a[n - 1])
            j--;
        if (i == n)
            cout << 0 << '\n';
        else if (a[i - 1] == a[j + 1])
        {
            cout << j - i + 1 << '\n';
        }
        else
        {
            cout << min(n - i, j + 1) << '\n';
        }
    }

    return 0;
}
