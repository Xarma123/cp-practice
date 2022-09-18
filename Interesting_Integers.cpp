#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    for (lol k = 1; k <= t; k++)
    {
        lol a, b;
        cin >> a >> b;
        lol ans = 0;
        for (lol i = a; i <= b; i++)
        {
            string x = to_string(i);
            lol p = 1, s = 0;
            for (lol j = 0; j < x.size(); j++)
            {
                p = p * 1ll * (x[j] - '0');
                s += (x[j] - '0');
            }
            if (p % s == 0)
            { 
                ans++;
                cout<<x<<endl;
            }
        }

        cout << "Case #" << k << ": " << ans << endl;
    }

    return 0;
}