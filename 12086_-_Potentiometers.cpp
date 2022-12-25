#include <bits/stdc++.h>
#define lol long long
using namespace std;
class BIT
{
public:
    vector<lol> a;
    lol n;

    BIT(lol n)
    {
        this->n = n + 1;
        a.assign(n + 1, 0);
    }

    BIT(vector<lol> a)
        : BIT(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    lol sum(lol idx)
    {
        lol ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += a[idx];
        return ret;
    }

    lol sum(lol l, lol r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(lol idx, lol delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            a[idx] += delta;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol caseno = 1;
    while (1)
    {
        lol n;
        cin >> n;
        if (n == 0)
            return 0;
        vector<lol> a;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            a.push_back(t);
        }
        BIT tree(a);
        string s;
        cin >> s;
        cout << "Case " << caseno << ":" << endl;
        while (s != "END")
        {

            if (s == "M")
            {
                lol x, y;
                cin >> x >> y;
                cout << tree.sum(x - 1, y - 1) << endl;
            }
            else
            {
                lol x, y;
                cin >> x >> y;
                tree.add(x - 1, y - a[x - 1]);
                a[x - 1] = y;
            }

            cin >> s;
        }
        caseno++;
    }

    return 0;
}