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
    lol ans = 0;
    set<lol> x;
    x.insert(0);
    lol sum = 0;
    for (lol i = 0; i < n; i++)
    {
        sum += a[i];
        if (x.count(sum))
        {
            ans++;
            x.clear();
            x.insert(a[i]);
            sum = a[i];
            x.insert(0);
        }
        else
        {
            x.insert(sum);
        }
    }

    cout << ans;

    return 0;
}