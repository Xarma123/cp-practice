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
        lol a, b, c;
        cin >> a >> b >> c;

        if (((long long)abs(b - c) % 2 == 0) && ((long long)abs(b - c) % 2 == 0) / 2 <= a)
            cout << 1 << " ";
        else
            cout << 0 << " ";
        if (((long long)abs(a - c) % 2 == 0) && ((long long)abs(a - c) % 2 == 0) / 2 <= b)
            cout << 1 << " ";
        else
            cout << 0 << " ";
        if (((long long)abs(a - b) % 2 == 0) && ((long long)abs(a - b) % 2 == 0) / 2 <= c)
            cout << 1 << " ";
        else
            cout << 0 << " ";

        cout << '\n';
    }

    return 0;
}
