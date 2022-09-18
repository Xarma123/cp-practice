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
        vector<lol> ev, od;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            if (t % 2 == 0)
                ev.push_back(t);
            else
                od.push_back(t);
        }
        if (is_sorted(ev.begin(), ev.end()) && is_sorted(od.begin(), od.end()))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}