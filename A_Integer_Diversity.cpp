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
        set<lol> x;
        while (n--)
        {
            lol t;
            cin >> t;
            if (x.count(t))
            {
                t = -1 * t;
                x.insert(t);
            }
            else
                x.insert(t);
        }
        cout << x.size() << endl;
    }

    return 0;
}