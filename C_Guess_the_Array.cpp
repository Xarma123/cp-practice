#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];

    cout << "? " << 1 << " " << 2 << endl;
    lol v1;
    cin >> v1;
    cout << "? " << 1 << " " << 3 << endl;
    lol v2;
    cin >> v2;
    cout << "? " << 2 << " " << 3 << endl;
    lol v3;
    cin >> v3;
    a[1] = (v1 - v2 + v3) / 2;
    a[0] = v1 - a[1];
    a[2] = v2 - a[0];
    for (lol i = 3; i < n; i++)
    {
        cout << "? " << 1 << " " << i + 1 << endl;
        cin >> v1;
        a[i] = v1 - a[0];
    }
    cout << "! ";
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}