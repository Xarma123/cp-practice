#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
   
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        multiset<lol> mp;
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            s += q;
            mp.insert(q);
        }

        queue<lol> w;
        w.push(s);
        while (!w.empty())
        {
            lol q = w.front();
            w.pop();
            if (mp.count(q)>0)
            {
                mp.erase(mp.find(q));
            }
            else if (q > 1)
            {
                lol a = (long long)ceill((q / (long double)2));
                lol b = (long long)floorl((q / (long double)2));
                w.push(a);
                w.push(b);
            }
            else
                break;
            if (mp.size() < w.size())
                break;
        }
        if (mp.size() == 0)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
    }

    return 0;
}