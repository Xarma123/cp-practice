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
        if (a.size() % 2 != 0)
            cout << "NO" << endl;
        else
        {
            lol e1 = a.size() - 1;
            lol e2 = ((a.size()) / 2) - 1;
            bool f = true;
            while (e2 >= 0)
            {
                if (a[e1] == a[e2])
                {
                    e1--;
                    e2--;
                }
                else
                {
                    f = false;
                    break;
                }
            }
            if (f)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}