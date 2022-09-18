#include <bits/stdc++.h>
#define lol long long
using namespace std;
string bread;
lol nb, ns, nc;
lol pb, ps, pc;
lol r;
lol B = 0, S = 0, C = 0;
bool check(lol k)
{
    lol mon = r;

    lol bn = k * B;
    if (bn >= nb)
        bn -= nb;
    else
        bn = 0;
    if (mon >= bn * pb)
        mon -= bn * pb;
    else
        return false;

    lol sn = k * S;
    if (sn >= ns)
        sn -= ns;
    else
        sn = 0;
    if (mon >= sn * ps)
        mon -= sn * ps;
    else
        return false;

    lol cn = k * C;
    if (cn >= nc)
        cn -= nc;
    else
        cn = 0;
    if (mon >= cn * pc)
        mon -= cn * pc;
    else
        return false;
    return mon >= 0;
}
int main()
{
    cin >> bread >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for (lol i = 0; i < bread.size(); i++)
    {
        if (bread[i] == 'B')
            B++;
        if (bread[i] == 'S')
            S++;
        if (bread[i] == 'C')
            C++;
    }

    lol s = 0;
    lol e = 1e18;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (check(m))
            s = m;
        else
            e = m;
    }
    cout << s;
    return 0;
}