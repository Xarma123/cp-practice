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
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                c++;
        }
        cout << (c / 2) + (c % 2) + n - c << '\n';
    }

    return 0;
}