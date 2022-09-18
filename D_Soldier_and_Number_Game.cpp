#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<lol> sieve(5000001, 0);
    vector<lol> p(5000001, 0);
    vector<lol> pt(5000001, 0);
    for (lol i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == 0)
        {
            for (lol j = i; j <= 5000000; j += i)
            {
                sieve[j] = i;
            }
        }
        p[i] = p[i / sieve[i]] + 1;
        pt[i] = p[i] + pt[i - 1];
    }
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        cout << pt[a] - pt[b] << '\n';
    }
    return 0;
}