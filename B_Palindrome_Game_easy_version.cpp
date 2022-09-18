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
        string s;
        cin >> s;
        lol z = 0;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z++;
        }
        if (z % 2 != 0)
        {
            if (z > 1)
                cout << "ALICE" << endl;
            else
                cout << "BOB" << endl;
        }
        else
        {

            cout << "BOB" << endl;
        }
    }

    return 0;
}