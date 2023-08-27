#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol j = n - 1;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            while (j >= 0 && a[j] < i + 1)
                j--;
            h[i] = j + 1;
        }
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != h[i])
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}