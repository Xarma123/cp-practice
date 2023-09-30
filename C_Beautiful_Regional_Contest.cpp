#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        lol g = 0;
        lol s = 0;
        lol b = 0;
        for (lol i = 0; i < n; i++)
        {
            if (g == 0)
            {
                if (i + 1 < n && p[i] > p[i + 1])
                {
                    g = i + 1;
                }
            }
            else if (s == 0)
            {
                if (i + 1 < n && p[i] > p[i + 1])
                {
                    if (i + 1 - g > g)
                        s = i + 1 - g;
                }
            }
            else
            {
                if (i + 1 < n && p[i] > p[i + 1])
                {
                    if ((i + 1) <= (n / 2))
                        b = i + 1 - s - g;
                }
            }
        }
        if (b <= g)
            b = 0;
        if (g == 0 || b == 0 || s == 0)
        {
            g = s = b = 0;
        }

        cout << g << " " << s << " " << b << '\n';
    }
}