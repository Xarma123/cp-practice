#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        lol o = 0;
        lol z = 0;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] == '0')
                z++;
            else
                o++;
        }
        if (z == o)
        {
            if (a[0] == '0')
            {
                o--;
            }
            else
                z--;
        }
        cout << min(o, z) << endl;
    }

    return 0;
}