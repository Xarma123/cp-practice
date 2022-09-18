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
        lol f = floorl(sqrtl(n));
        set<lol> x;
        for (lol i = 0; i <= f; i++)
        {
            x.insert(i);
            if(i!=0)
            x.insert((n / i));
        }
        cout << x.size() << endl;
        for (auto i = x.begin(); i != x.end(); i++)
        {
            cout << (*i) << " ";
        }
        cout << endl;
    }

    return 0;
}