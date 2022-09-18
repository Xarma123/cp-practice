#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool p(string a)
{
    lol s = 0;
    lol e = a.size() - 1;
    while (s < e)
    {
        if (a[s] != a[e])
            return false;
        s++;
        e--;
    }
    return true;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        bool pl = p(a);
        lol ans = 1;
        if (pl)
        {
            cout << 1 << endl;
        }
        else
        {
            if (k == 0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}