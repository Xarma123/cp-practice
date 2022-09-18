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
        lol n, q;
        cin >> n >> q;
        lol a[n];
        string s1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s1.push_back('0');
        }
        lol s = -1, e = n;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            if (m == -1)
                s = -1;
            else if (m == n)
                e = n;
            else
            {
                lol c = q;
                for (lol i = m; i < n; i++)
                {
                    if (a[i] > c)
                    {
                        c--;
                    }
                }
                if (c < 0)
                    s = m;
                else
                    e = m;
            }

            for (lol i = 0; i < n; i++)
            {
                if (a[i] <= q)
                    s1[i] = '1';
                else if (i >= e)
                    s1[i] = '1';
            }
        }
        cout << s1 << endl;
    }
    return 0;
}