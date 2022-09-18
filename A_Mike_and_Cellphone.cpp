#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol q;
    lol cmn = LONG_LONG_MAX;
    lol cmx = LONG_LONG_MIN;
    lol rmn = LONG_LONG_MAX;
    lol rmx = LONG_LONG_MIN;
    lol c8 = 0, c9 = 0, c7 = 0, c0 = 0;
    string s;
    cin >> s;
    for (lol i = 0; i < n; i++)
    {
        q = s[i] - '0';
        if (q == 1)
        {
            cmn = min(cmn, 1ll);

            cmx = max(cmx, 1ll);
            rmn = min(rmn, 1ll);
            rmx = max(rmx, 1ll);
        }
        else if (q == 2)
        {
            cmn = min(cmn, 2ll);
            cmx = max(cmx, 2ll);
            rmn = min(rmn, 1ll);
            rmx = max(rmx, 1ll);
        }
        else if (q == 3)
        {
            cmn = min(cmn, 3ll);
            cmx = max(cmx, 3ll);
            rmn = min(rmn, 1ll);
            rmx = max(rmx, 1ll);
        }
        else if (q == 4)
        {
            cmn = min(cmn, 1ll);
            cmx = max(cmx, 1ll);
            rmn = min(rmn, 2ll);
            rmx = max(rmx, 2ll);
        }
        else if (q == 5)
        {
            cmn = min(cmn, 2ll);
            cmx = max(cmx, 2ll);
            rmn = min(rmn, 2ll);
            rmx = max(rmx, 2ll);
        }
        else if (q == 6)
        {
            cmn = min(cmn, 3ll);
            cmx = max(cmx, 3ll);
            rmn = min(rmn, 2ll);
            rmx = max(rmx, 2ll);
        }
        else if (q == 7)
        {
            c7++;
            cmn = min(cmn, 1ll);
            cmx = max(cmx, 1ll);
            rmn = min(rmn, 3ll);
            rmx = max(rmx, 3ll);
        }
        else if (q == 8)
        {
            c8++;
            cmn = min(cmn, 2ll);
            cmx = max(cmx, 2ll);
            rmn = min(rmn, 3ll);
            rmx = max(rmx, 3ll);
        }
        else if (q == 9)
        {
            c9++;
            cmn = min(cmn, 3ll);
            cmx = max(cmx, 3ll);
            rmn = min(rmn, 3ll);
            rmx = max(rmx, 3ll);
        }
        else
        {
            c0++;
            cmn = min(cmn, 2ll);
            cmx = max(cmx, 2ll);
            rmn = min(rmn, 4ll);
            rmx = max(rmx, 4ll);
        }
    }
    if ((rmx - rmn == 3))
        cout << "YES" << endl;
    else
    {
        if (((rmx - rmn) == 2 && (cmx - cmn) == 2))
        {
            if (c0)
                cout << "NO" << endl;
            else
            {

                if (c7 == 0 && c9 == 0 && c8)
                    cout << "NO" << endl;
                else
                    cout << "YES" << endl;
            }
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}