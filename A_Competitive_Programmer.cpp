#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        lol z = 0, e = 0, su = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            lol x = s[i] - '0';
            if (x == 0)
                z++;
            else if (x % 2 == 0)
                e++;
            su += x;
        }
        if (z > 0)
        {
            z--;
            if (su % 3 == 0 && (z + e) >= 1)
                cout << "red" << endl;
            else
                cout << "cyan" << endl;
        }
        else
            cout << "cyan" << endl;
    }

    return 0;
}