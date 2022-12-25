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
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol k, x;
            cin >> k >> x;
            a[k - 1] = x;
        }
        else
        {
            lol k;
            cin >> k;
            cout << a[k - 1] << '\n';
        }
    }

    return 0;
}