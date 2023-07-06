#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        lol ans1 = 0, ans2 = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                ans1++;
            if (a[i] != b[n - 1 - i])
                ans2++;
        }
        if (ans1 == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        if (ans1 % 2 != 0)
        {
            ans1 += (ans1 - 1);
        }
        else
        {
            ans1 *= 2ll;
        }
        if (ans2 % 2 == 0)
        {
            if (ans2 != 0)
                ans2 += (ans2 - 1);
            else
            {
                ans2 = 2;
            }
        }
        else
        {
            ans2 *= 2ll;
        }
        cout << min(ans1, ans2) << '\n';
    }
}