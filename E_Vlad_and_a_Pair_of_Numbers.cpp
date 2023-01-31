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
        lol x;
        cin >> x;
        if (x % 2)
            cout << -1 << '\n';
        else
        {
            vector<lol> b;
            lol l = 0;
            while (x)
            {
                b.push_back(x % 2);
                if (l && (x % 2))
                    break;
                l = b.back();
                x /= 2;
            }
            if (x)
            {
                cout << -1 << '\n';
            }
            else
            {
                lol a = 0, a1 = 0;
                for (lol i = 0; i < b.size(); i++)
                {
                    if (b[i])
                    {
                        a |= (1ll << i);
                        a |= (1ll << (i - 1));
                        a1 |= (1ll << (i - 1));
                    }
                }
                cout << a << " " << a1 << '\n';
            }
        }
    }

    return 0;
}