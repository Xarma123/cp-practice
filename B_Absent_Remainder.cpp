#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
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
        sort(a, a + n);

        lol e = n - 1;
        lol c = n / 2;
        while (c--)
        {
            cout << a[e] << " " << a[0] << endl;
            e--;
        }
    }

    return 0;
}