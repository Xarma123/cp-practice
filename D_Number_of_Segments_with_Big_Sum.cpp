#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, s;
    cin >> n >> s;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol si = 0, sum = 0, e = 0, ans = 0;
    while (e != n)
    {
        sum += a[e];

        while (sum >= s)
        {   
            ans += n - e ;
            sum -=a[si];
            si++;
        }

        e++;
    }
    cout << ans;
    return 0;
}