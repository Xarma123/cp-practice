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
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol q;
    cin >> q;
    while (q--)
    {
        lol h;
        cin >> h;
        lol i = lower_bound(a, a + n, h) - a;
        i--;
        if (i >= 0)
            cout << a[i] << " ";
        else
            cout << 'X' << " ";
        i = upper_bound(a, a + n, h) - a;
        if (i == n)
            cout << 'X' << endl;
        else
            cout << a[i] << endl;
    }

    return 0;
}