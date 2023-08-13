#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol j = n - 2;
        while (j >= 0 && a[j] == a[n - 1])
            j--;
        if (j < 0)
            cout << -1 << '\n';
        else
        {
            cout << j+1 << " " << n - j-1 << '\n';
            for (lol i = 0; i <= j; i++)
            {
                cout << a[i] << " ";
            }
            cout << '\n';
            for (lol i = j + 1; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << '\n';
        }
    }
}