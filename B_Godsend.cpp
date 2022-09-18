#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol od = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            od++;
    }
    if (od == 0)
        cout << "Second";
    else
    {
        cout << "First";
    }

    return 0;
}