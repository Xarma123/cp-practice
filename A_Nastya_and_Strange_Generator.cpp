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
        lol p[n];
        map<lol, lol> ind;
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
            ind[p[i]] = i;
        }
        bool ans = true;

        lol last = n;
        lol v = 1;
        while (v <= n)
        {
            lol i = ind[v];
            lol temp = ind[v];
            while (i < last)
            {
                if (p[i] != v)
                {
                    ans = false;
                    break;
                }
                i++;
                v++;
            }
            if (!ans)
                break;
            last = temp;
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}