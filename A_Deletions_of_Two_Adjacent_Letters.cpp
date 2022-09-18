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
        char c;
        cin >> c;
        lol i;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == c)
            {
                if (i % 2 == 0 && ((a.size() - 1) - i) % 2 == 0)
                    break;
            }
        }
        if (i == a.size())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}