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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        swap(a[n - 2], a[0]);
        if (a[n - 1] == a[n - 2])
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (lol i = 0; i < n; i++)
            {
                cout << a[n - 1 - i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}