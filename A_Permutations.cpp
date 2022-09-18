#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    lol i;

    for (i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            break;
    }
    cout << n - i-1;

    return 0;
}