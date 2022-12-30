#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol M = 1e9 + 7;
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
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
        return (long long)res;
    }
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
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol ans = (((((3ll * n - 3 + (n + 1) * 1ll * (2ll * n + 1) + (n - 1) * 1ll * (2ll * n - 1)) % M) * 1ll * n) % M) * 1ll * modInverse(6)) % M;

        cout << (ans * 2022ll) % M << endl;
    }

    return 0;
}