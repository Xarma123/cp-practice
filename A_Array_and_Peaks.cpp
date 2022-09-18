#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        for (lol i = 1; k && (i < n - 1); i += 2)
        {
            swap(a[i], a[i + 1]);
            k--;
        }
        if (k)
            cout << -1 << endl;
        else
        {
            for (lol i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}