#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (b.size() == a.size())
        {
            lol ans = 0;
            for (lol i = 0; i < b.size(); i++)
            {
                if (b[i] != a[i])
                {
                    ans += (abs((long long)(b[i] - a[i])));
                    ans += 9ll * ((long long)b.size() - i - 1);
                    break;
                }
            }
            cout << ans << '\n';
        }
        else
        {
            cout << b[0] - '0' + 9ll * (b.size() - 1) << '\n';
        }
    }
}