#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    lol n = q;
    vector<lol> p;
    for (lol i = 2; i * 1ll * i <= q; i++)
    {
        bool f = false;
        while (q % i == 0)
        {
            p.push_back(i);
            q /= i;
        }
    }
    if (q > 1)
        p.push_back(q);
    if (p.size() <= 1)
    {
        cout << 1 << endl;
        cout << 0;
    }
    else if (p.size() == 2)
    {
        cout << 2;
    }
    else
    {
        cout << 1 << endl;
        cout <<(p[0] * 1ll * p[1]);
    }

    return 0;
}