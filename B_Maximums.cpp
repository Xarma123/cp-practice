#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol v = 0;
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] + v << " ";
        v = max(v, a[i] + v);
    }

    return 0;
}