#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol u, v;
        cin >> u >> v;
        u *= u;
        v *= v;
        cout << u << " " << -v << endl;
    }

    return 0;
}