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
    lol mx = 0;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > mx)
            break;
        else if (a[i] == mx)
            mx++;
    }
    if (i == n)
        cout << -1;
    else
        cout << i + 1;

    return 0;
}