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
    sort(a, a + n);
    bool f = true;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] != 1)
            f = false;
        if (i == n - 1 && f)
        {
            cout << 2;
        }
        else if (i == 0)
            cout << 1 << " ";
        else
        {
            cout << a[i - 1] << " ";
        }
    }

    return 0;
}