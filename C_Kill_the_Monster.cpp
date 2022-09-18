#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol hc, dc;
        cin >> hc >> dc;
        lol hm, dm;
        cin >> hm >> dm;
        lol k, w, a;
        cin >> k >> w >> a;
        lol i;
        for (i = 0; i <= k; i++)
        {
            lol ndc = dc + i * w;
            lol nhc = hc + (k - i) * a;
            lol m = ceill(nhc / (long double)dm);
            lol c = ceill(hm / (long double)ndc);
            if (m >= c)
                break;
        }
        if (i <= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}