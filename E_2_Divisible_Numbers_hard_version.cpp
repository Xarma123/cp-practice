#include <bits/stdc++.h>
#define lol long long
using namespace std;
//a
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        lol q = a * 1ll * b;
        vector<lol> div;
        for (lol i = 1; i * 1ll * i <= a; i++)
        {
            if (a % i == 0)
            {
                div.push_back(i);
                div.push_back(a / i);
            }
        }
        vector<lol> div2;
        for (lol i = 1; i * 1ll * i <= b; i++)
        {
            if (b % i == 0)
            {
                div2.push_back(i);
                div2.push_back(b / i);
            }
        }

        bool ans = false;
        for (auto d1 : div)
        {
            for (auto d2 : div2)
            {
                lol de = d1 * 1ll * d2;
                if (q % de == 0)
                {
                    lol op = q / de;
                    lol l = (a / de) * 1ll * de;
                    while (l <= a)
                        l += de;
                    lol r = (c / de) * 1ll * de;

                    if (l <= r)
                    {
                        lol l2 = (b / op) * 1ll * op;
                        while (l2 <= b)
                            l2 += op;
                        lol r2 = (d / op) * 1ll * op;

                        if (l2 <= r2)
                        {
                            ans = true;
                            cout << l << " " << l2 << endl;
                        }
                    }
                    if (ans)
                        break;

                    swap(op, de);
                    l = (a / de) * 1ll * de;
                    while (l <= a)
                        l += de;
                    r = (c / de) * 1ll * de;

                    if (l <= r)
                    {
                        lol l2 = (b / op) * 1ll * op;
                        while (l2 <= b)
                            l2 += op;
                        lol r2 = (d / op) * 1ll * op;

                        if (l2 <= r2)
                        {
                            ans = true;
                            cout << l << " " << l2 << endl;
                        }
                    }
                    if (ans)
                        break;
                    swap(op, de);
                }
            }
            if (ans)
                break;
        }

        if (!ans)
            cout << -1 << " " << -1 << endl;
    }

    return 0;
}