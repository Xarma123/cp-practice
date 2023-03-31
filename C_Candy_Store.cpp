#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
       
        lol ans = 1;
        lol lcm = b[0];
        lol gc = a[0];
        for (lol i = 1; i < n; i++)
        {
            lol nlcm = lcm * 1ll * b[i] / __gcd(lcm, b[i]);
         
            lol w = nlcm / b[i];
            if (a[i] % w == 0)
            {
                if (gc % (nlcm / lcm) == 0)
                {
                    gc /= (nlcm / lcm);
                    lcm = nlcm;
                    gc = __gcd((a[i] / w), gc);
                    continue;
                }
            }
            ans++;
            lcm = b[i];
            gc = a[i];
        }
        cout << ans << '\n';
    }

    return 0;
}