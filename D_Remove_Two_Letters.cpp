#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        lol q = A / M;
        lol t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
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
        string s;
        cin >> s;
        lol prefix_hash[n];
        lol hash = 0, pow = 1;
        lol p = 111111, m = 1e9 + 9;
        for (lol i = 0; i < n; i++)
        {
            hash = (hash + ((s[i] - 'a' + 1ll) * 1ll * pow) % m) % m;
            prefix_hash[i] = hash;
            pow = (pow * p) % m;
        }
        lol p_inv = p * 1ll * p;
        p_inv = modInverse(p_inv, m);
        lol prefix_hash1[n];
        lol hash1 = 0, pow1 = 1;
        lol p1 = 31, m1 = 1e9 + 7;
        for (lol i = 0; i < n; i++)
        {
            hash1 = (hash1 + ((s[i] - 'a' + 1ll) * 1ll * pow1) % m1) % m1;
            prefix_hash1[i] = hash1;
            pow1 = (pow1 * p1) % m1;
        }
        lol p_inv1 = p1 * 1ll * p1;
        p_inv1 = modInverse(p_inv1, m1);
        set<pair<lol, lol>> q;
        for (lol i = 0; i < n - 1; i++)
        {
            lol v1 = 0;
            if (i)
            {
                v1 += prefix_hash[i - 1];
            }
            lol v2 = 0;
            if (i + 2 < n)
            {
                v2 += (((prefix_hash[n - 1] - prefix_hash[i + 1] + m) % m) * 1ll * p_inv) % m;
            }
            v1 = (v1 + v2) % m;
            lol v11 = 0;
            if (i)
            {
                v11 += prefix_hash1[i - 1];
            }
            lol v21 = 0;
            if (i + 2 < n)
            {
                v21 += (((prefix_hash1[n - 1] - prefix_hash1[i + 1] + m1) % m1) * 1ll * p_inv1) % m1;
            }
            v11 = (v11 + v21) % m1;
            q.insert({v1, v11});
        }
        cout << fixed << (long long)q.size() << '\n';
    }

    return 0;
}