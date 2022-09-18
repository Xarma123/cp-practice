#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a;
        cin >> a;
        lol ans = 0;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] != '0')
            {
                if (i != a.size() - 1)
                    ans++;
                ans += (a[i] - '0');
            }
        }
        cout << ans << endl;
    }

    return 0;
}