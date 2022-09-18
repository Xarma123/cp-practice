#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol N = n;
    vector<lol> p;
    for (lol i = 2; i <= n; i++)
    {
        while (N % i == 0)
        {
            p.push_back(i);
            N /= i;
        }
    }
    if (p.size() < k)
        cout << -1;
    else
    {
        lol v = 1;
        for (lol i = 0; i < k - 1; i++)
        {

            cout << p[i] << " ";
            v *= p[i];
        }
        cout << n / v;
    }

    return 0;
}