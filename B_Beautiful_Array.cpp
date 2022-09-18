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
        lol n, k, b, s;
        cin >> n >> k >> b >> s;
        if (s / k == b)
        {
            for (lol i = 0; i < n - 1; i++)
            {
                cout << 0 << " ";
            }
            cout << s << endl;
        }
        else if (k == 1)
        {
            if (s == b)
            {
                for (lol i = 0; i < n - 1; i++)
                {
                    cout << 0 << " ";
                }
                cout << s << endl;
            }
            else
                cout << -1 << endl;
        }
        else if (s / k < b)
        {
            cout << -1 << endl;
        }
        else
        {
            lol c = 0;
            while (s > b * 1ll * k + k - 1)
            {
                s -= k - 1;
                c++;
            }
            s += k - 1;
           
            c--;
            if (c + 1 <= n - 1)
            {
                cout << s - (b * 1ll * k + k - 1) << " ";
                n -= c;
                n--;
                while (c--)
                {
                    cout << k - 1 << " ";
                }
                n--;
                cout << s -(s - (b * 1ll * k + k - 1) )<< " ";
                while (n--)
                {
                    cout << 0 << " ";
                }
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}