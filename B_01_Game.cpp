#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol z = 0, o = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                z++;
            else
                o++;
        }
        if (z > o)
            swap(z, o);
        if (z % 2 == 0)
            cout << "NET" << endl;
        else
            cout << "DA" << endl;
    }

    return 0;
}