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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol c = 1;
        for (lol i = n - 1 - k; i < n; i++)
        {
            a[i] = (c++);
        }
        c = n;
        for (lol i = 0; i < n - 1 - k; i++)
        {
            a[i] = (c--);
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
