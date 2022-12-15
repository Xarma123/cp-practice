#include <bits/stdc++.h>
#define lol long long
using namespace std;

#define MAXN 100001

int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)

        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {

        if (spf[i] == i)
        {

            for (int j = i * i; j < MAXN; j += i)

                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    sieve();
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> f;
        bool ans = false;
        lol g = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > (long long)1e5)
            {
                
            }
            set<int> x = getFactorization((int)a[i]);
            for (auto e : x)
            {
                f[e]++;
                if (f[e] > 1)
                    ans = true;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}