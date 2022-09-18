#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol q;
        cin >> q;
        string n;
        cin >> n;
        char o1 = '\0';
        char o2 = '\0';
        for (lol i = 0; i < n.size(); i++)
        {
            if ((n[i] - '0') % 2 != 0)
            {
                if (o1 == '\0')
                    o1 = n[i];
                else if (o2 == '\0')
                    o2 = n[i];
                else
                    break;
            }
        }
        if (o1 == '\0' || o2 == '\0')
            cout << -1 << endl;
        else
            cout << o1 << o2 << endl;
    }

    return 0;
}