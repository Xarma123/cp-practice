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
            a[i] = i + 1;
        }
        for (lol i = 0; i + 1 < n; i += 2)
        {
            swap(a[i], a[i + 1]);
        }
        if (n % 2 != 0)
            swap(a[0], a[n - 1]);
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}