#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        lol ans = 0;
        if (a < b)
            swap(a, b);
        lol k = a - b;
        k = min(a / 2, k);
        k = min(b, k);
        ans += k;
        a = a - 2 * k;
        b = b - k;
        if (a >= 2&&a==b)
        {
            lol l = (a - 2) / 3;
            ans += 1 + l * 2 + 1 * ((a - 2) % 3 > 0);
        } 
        cout<<ans<<endl;
    }

    return 0;
}