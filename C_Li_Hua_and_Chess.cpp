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
        lol n, m;
        cin >> n >> m;
        cout << "? " << 1 << " " << 1 << endl;
        lol c1;
        cin >> c1;
        if (c1 + 1 <= n && c1 + 1 <= m)
        {
            cout << "? " << c1 + 1 << " " << c1 + 1 << endl;
            lol x1;
            cin >> x1;
            cout << "? " << c1 + 1 - x1 << " " << c1 + 1 << endl;
            lol x;
            cin >> x;
            if (x == 0)
            {
                cout << "! " << c1 + 1 - x1 << " " << c1 + 1 << endl;
            }
            else
                cout << "! " << c1 + 1 << " " << c1 + 1 - x1 << endl;
        }
        else if (c1 + 1 <= n)
        {
            cout << "? " << c1 + 1 << " " << 1 << endl;
            lol x;
            cin >> x;
            cout << "! " << c1 + 1 << " " << 1 + x << endl;
        }
        else if (c1 + 1 <= m)
        {
            cout << "? " << 1 << " " << c1 + 1 << endl;
            lol x;
            cin >> x;
            cout << "! " << 1 + x << " " << c1 + 1 << endl;
        }
    }

    return 0;
}