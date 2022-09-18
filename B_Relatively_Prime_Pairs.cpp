#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for (lol i = l; i < r; i += 2)
    {
        cout << i << " " << i + 1 << endl;
    }

    return 0;
}