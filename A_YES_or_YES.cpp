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
        string s;
        cin >> s;
        bool f = true;
        if (!(s[0] == 'Y' || s[0] == 'y'))
            f = false;
        if (!(s[1] == 'E' || s[1] == 'e'))
            f = false;
        if (!(s[2] == 'S' || s[2] == 's'))
            f = false;
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}