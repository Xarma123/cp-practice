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
        vector<lol> x(4);
        bool z = false, o = false;
        for (lol i = 0; i < 4; i++)
        {
            cin >> x[i];
            if (x[i] == 0)
                z = true;
            else
                o = true;
        }
        if (o && !z)
        {
            cout << 2 << endl;
        }
        else if (o && z)
        {
            cout << 1 << endl;
        }
        else if (!o)
            cout << 0 << endl;
    }

    return 0;
}