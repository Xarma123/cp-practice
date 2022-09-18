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
        lol n;
        cin >> n;
        string s;
        cin >> s;
        if (n % 2 == 0)
        {
            bool od = false, ev = false;
            for (lol i = 1; i < n; i += 2)
            {
                if ((s[i] - '0') % 2 == 0)
                    ev = true;
                else
                    od = true;
            }
            if (ev)
                cout << 2 << '\n';
            else
                cout << 1 << '\n';
        }
        else
        {
            bool od = false, ev = false;
            for (lol i = 0; i < n; i += 2)
            {
                if ((s[i] - '0') % 2 == 0)
                    ev = true;
                else
                    od = true;
            }
            if (od)
                cout << 1 << '\n';
            else
                cout << 2 << '\n';
        }
    }

    return 0;
}