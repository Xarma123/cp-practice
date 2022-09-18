#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        lol teams = 0;
        teams += min((a - b) / 2, b);
        b = b - teams;
        teams += b / 2;
        cout << teams << endl;
    }

    return 0;
}