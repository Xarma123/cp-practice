#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        multiset<lol> a, b;
        lol n;
        cin >> n;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            while (v % 2 == 0)
                v /= 2;
            a.insert(v);
        }
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            while (v % 2 == 0)
                v /= 2;
            b.insert(v);
        }
        while (!b.empty())
        {
            lol x = *b.rbegin();
            if (!a.count(x))
            {
                if (x == 1)
                    break;
                b.erase(b.find(x));
                b.insert(x / 2);
            }
            else
            {
                b.erase(b.find(x));
                a.erase(a.find(x));
            }
        }

        cout << (b.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}