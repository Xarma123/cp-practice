#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k, l, R, s, sk;
    cin >> n >> k >> l >> R >> s >> sk;

    lol out = n - k;
    if (out != 0)
    {
        lol ss = s - sk;
        lol v = ss / out;
        lol r = ss % out;
        while (out--)
        {
            if (r)
                r--, cout << v + 1 << " ";
            else
                cout << v << " ";
        }
    }
    lol v = sk / k;
    lol r = sk % k;
    while (k--)
    {
        if (r)
            r--, cout << v + 1 << " ";
        else
            cout << v << " ";
    }

    return 0;
}