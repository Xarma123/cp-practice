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
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i + 1] = c[i] + a[i];
    }
    sort(a, a + n);
    lol c1[n + 1];
    c1[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        c1[i + 1] = c1[i] + a[i];
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol l, r;
            cin >> l >> r;
            cout << c[r] - c[l - 1] << endl;
        }
        else
        {

            lol l, r;
            cin >> l >> r;
            cout << c1[r] - c1[l - 1] << endl;
        }
    }

    return 0;
}