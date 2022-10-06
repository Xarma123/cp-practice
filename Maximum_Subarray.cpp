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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol m;
        cin >> m;
        lol b[m];
        lol posi = 0;
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
            if (b[i] > 0)
                posi += b[i];
        }
        lol mxpre = 0;
        lol cp = 0;
        for (lol i = 0; i < n; i++)
        {
            cp += a[i];
            mxpre = max(mxpre, cp);
        }
        lol mxsuf = 0;
        cp = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            cp += a[i];
            mxsuf = max(mxsuf, cp);
        }
        lol max_so_far = 0, max_ending_here = 0;

        for (lol i = 0; i < n; i++)
        {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;

            if (max_ending_here < 0)
                max_ending_here = 0;
        }

        cout << max(max(mxpre, mxsuf) + posi, max_so_far) << endl;
    }

    return 0;
}