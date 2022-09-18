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
        lol check=0;
        for (lol i = 0; i < 2 * n; i++)
        {
            lol t;
            cin >> t;
            x.insert(t); 
            check = check^t;
        }
        if (x.size() != n||check!=0)
        {
            cout << "NO" << endl;
        }
        else
        {
            bool flag = true;
            lol s = 0;
            lol c = 0;
            for (auto i = x.rbegin(); i != x.rend(); i++)
            {
                if (((*i) - 2 * s) % (2 * (n - 1 - c) + 2) != 0 || ((*i) - 2 * s) <= 0)
                {

                    flag = false;
                    break;
                }
                else
                {
                    s += ((*i) - 2 * s) / (2 * (n - 1 - c) + 2);
                    c++;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}