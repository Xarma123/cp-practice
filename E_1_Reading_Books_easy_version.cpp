#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    multiset<lol> Alc, Bob, Both;
    while (n--)
    {
        lol t, a, b;
        cin >> t >> a >> b;
        if (a && b)
            Both.insert(t);
        else if (a)
            Alc.insert(t);
        else if (b)
            Bob.insert(t);
    }
    lol ans = 0;
    while (k--)
    {
        lol T = LONG_LONG_MAX;
        if (!Alc.empty() && !Bob.empty())
        {
            T = (*Alc.begin()) + (*Bob.begin());
        }
        if (T == LONG_LONG_MAX)
        {
            if (!Both.empty())
            {
                T = (*Both.begin());
                Both.erase(Both.begin());
            }
        }
        else
        {
            if (!Both.empty())
            {
                if (T < (*Both.begin()))
                {
                    Alc.erase(Alc.begin());
                    Bob.erase(Bob.begin());
                }
                else
                {
                    T = (*Both.begin());
                    Both.erase(Both.begin());
                }
            }
            else
            {
                Alc.erase(Alc.begin());
                Bob.erase(Bob.begin());
            }
        }
        if (T == LONG_LONG_MAX)
        {
            ans = -1;
            break;
        }
        else
            ans += T;
    }
    cout << ans;

    return 0;
}