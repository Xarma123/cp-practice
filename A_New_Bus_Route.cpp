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
    sort(a, a + n);
    lol mn = LONG_LONG_MAX;
    for (lol i = 0; i < n - 1; i++)
    {
        mn = min(mn, a[i + 1] - a[i]);
    }
    lol c = 0;
    for (lol i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] == mn)
            c++;
    } 
    cout<<mn<<" "<<c;

    return 0;
}