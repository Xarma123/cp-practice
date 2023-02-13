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
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 2)
                s++;
        }
        lol c = 0;
        lol i;
        for (i = 0; i < n - 1; i++)
        {
            if (a[i] == 2)
                c++;
            if (c == s - c)
                break;
        }
        if (i == n - 1)
            cout << -1 << '\n';
        else
            cout << i + 1 << '\n';
    }

    return 0;
}