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
        lol a[n];
        map<lol, lol> x;

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x[a[i]]++;
        }
        for (auto i = x.begin(); i != x.end(); i++)
        {
            cout << (*i).first << " ";
            (*i).second--;
        }
        for (auto i = x.begin(); i != x.end(); i++)
        {
            lol c = (*i).second;
            if (c > 0)
            {
                while (c--)
                {
                    cout << (*i).first << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}