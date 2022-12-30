#include <bits/stdc++.h>
#define lol long long
using namespace std;
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int M = 1e9 + 7;
lol modInverse(int A)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {

        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
    }
    return -1;
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k;
    cin >> k;
    lol v[k];
    for (lol i = 0; i < k; i++)
    {
        cin >> v[i];
    }
    lol m = 1e9 + 7;
    lol fact[2000005], inv[2000005];
    for (lol i = 0; i < 2000005; i++)
    {
        if (i == 0)
            fact[i] = 1;
        else
            fact[i] = (fact[i - 1] * 1ll * i) % m;
        if (i)
            inv[i] = modInverse(i);
        if (i > 1)
        {
            inv[i] = (inv[i - 1] * 1ll * inv[i]) % m;
        }
    }
    lol ans = 1;
    lol c = v[0];
    for (lol i = 1; i < k; i++)
    {
        if (v[i] > 1)
            ans = (((((ans * 1ll * fact[c + v[i] - 1]) % m) * 1ll * inv[c]) % m) * 1ll * inv[v[i] - 1]) % m;
        c += v[i];
    }
    cout << ans;

    return 0;
}