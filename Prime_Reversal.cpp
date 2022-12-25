#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        lol z = 0, o = 0;
        for (auto c : a)
        {
            if (c == '0')
                z++;
            else
                o++;
        }
        for (auto c : b)
        {
            if (c == '0')
                z--;
            else
                o--;
        }
        if (z == 0 && o == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}