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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        bool ans = false;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == k)
                ans = true;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}