#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool p[101];
    memset(p, true, sizeof(p));
    vector<lol> prime;
    for (lol i = 2; i <= 100; i++)
    {
        if (p[i])
        {
            prime.push_back(i);
            for (lol j = i * 1ll * i; j <= 100; j += i)
            {
                p[j] = false;
            }
        }
    }

    while (1)
    {
        lol n, d;
        cin >> n >> d;
        if (n == 0 && d == 0)
            break;
        lol ans = 1;
        for (auto e : prime)
        {

            lol c = 0;
            lol v = e;
            while (n / v)
            {
                c += n / v;
                v *= e;
            }

            while (d % e == 0)
            {
                d /= e;
                c--;
            }

            if (c < 0)
            {
                ans = -1;
                break;
            }
            else
                ans = ans * 1ll * (c + 1);
        }
        // cout << endl;
        if (ans == -1 || d != 1)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}