#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {

        string s;
        cin >> s;
        lol z = s.size();
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                z = i;
                break;
            }
        }
        lol i;
        for (i = z - 1; i >= 0; i--)
        {
            if (s[i] == '1')
                break;
        }
        if (z == s.size() && i == -1)
            cout << s.size() << endl;
        else if (z == s.size() && i != -1)
            cout << z - i << endl;
        else if (z != s.size() && i == -1)
            cout << z - i << endl;
        else
            cout << z - i + 1 << endl;
    }

    return 0;
}