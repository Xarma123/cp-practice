#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        bool z = false;
        string s;
        cin >> s;
        for (auto e : s)
        {
            if (e == '0')
                z = true;
        }
        if (z)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
