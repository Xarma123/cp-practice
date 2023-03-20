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
        lol n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                c++;
        }
        if (c % 2)
            cout << -1 << '\n';
        else
        {
            if (x < y && 2ll * x >= y)
            {
                lol q = 0;
                for (lol i = 0; i < n; i++)
                {
                    if (a[i] != b[i])
                    {
                        lol j = i + 1;
                        while (j < n && a[j] == b[j])
                            j++;
                        q += (j - i) / 2;
                        i = j - 1;
                    }
                }
                cout << q * 1ll * x + ((c / 2) - q) * 1ll * y << '\n';
            }
            else if (y <= x)
            {
                cout<<(c/2)*1ll*y<<'\n';
            }
            else 
            {
                    
            }
        }
    }

    return 0;
}