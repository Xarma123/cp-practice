#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol nCrModp(lol n, lol r, lol p)
{
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;

    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    lol C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (lol i = 1; i <= n; i++)
    {

        // Fill entries of current row using previous
        // row values
        for (lol j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
int main()
{
    lol n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    lol c = 0;
    lol ans = 0;
    lol s = 0;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == '1')
            c++;
        if (c > k)
        {
            ans = (ans + nCrModp(i - s, k, 998244353ll)) % (998244353ll) - 1;
            while (c != k)
            {
                if (a[s] == '1')
                    c--;

                s++;
            }
        }
    }
    if (c == k)
        ans = (ans + nCrModp(i - s, k, 998244353ll)) % (998244353ll) - 1;

    cout << ans + 1;

    return 0;
}