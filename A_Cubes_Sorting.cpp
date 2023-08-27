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
        bool f = true;
        for (lol i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1])
                f = false;
        }
        if (f)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}