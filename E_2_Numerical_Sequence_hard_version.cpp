#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, lol> ev;
lol eval(lol a)
{
    if (ev.count(a))
        return ev[a];
    lol co = 0;
    for (lol i = 1; i <= 19; i++)
    {
        string s = "1";
        lol c = i - 1;
        while (c--)
            s += '0';
        string e = "";
        c = i;
        while (c--)
            e += '9';
        lol si = stoll(s);
        lol ei = stoll(e);
        if (ei <= a)
        {
            co += i * 1ll * (ei - si + 1);
        }
        else if (si <= a)
        {
            co += i * 1ll * (a - si + 1);
        }
        else
            break;
    }
    return ev[a] = co;
}
lol find(lol mx, lol r)
{
    for (lol i = 1; i <= 19; i++)
    {
        string s = "1";
        lol c = i - 1;
        while (c--)
            s += '0';
        string e = "";
        c = i;
        while (c--)
            e += '9';
        lol si = stoll(s);
        lol ei = stoll(e);
        if (ei > mx)
        {
            ei = mx;
        }

        if (i * 1ll * (ei - si + 1) < r)
        {
            r -= i * 1ll * (ei - si + 1);
        }
        else
        {
            lol k = r / i;
            if (r % i == 0)
                k--;
            si += k / i;
            r -= (k / i) * 1ll * i;
            s = to_string(si);
            return (long long)(s[r - 1] - '0');

            break;
        }
    }
    return -1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol k;
        cin >> k;
        if (k == 1)
        {
            cout << 1 << endl;
            continue;
        }
        lol c = 1;
        lol tot = 1;
        while (tot + eval(c + 1) < k)
        {
            c++;
            tot += eval(c);
        }

        cout << find(c + 1, k - tot) << endl;
    }
}