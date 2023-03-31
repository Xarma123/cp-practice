#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol f = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] * 1ll * a[i];
        a[i] %= 3ll;
        if (a[i] == 0)
            f++;
    }
    if (f <= n / 2)
    {
        cout << 0 << endl;
        lol q = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 1 && (q++) < n / 2)
            {
                cout << a[i];
            }
            else
                cout << 0;
        }
    }
    else
    {
        cout << 2 << endl;
        lol q = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 0 && (q++) < n / 2)
            {
                cout << a[i];
            }
            else
                cout << 1;
        }
    }

    return 0;
}