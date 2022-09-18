#include <bits/stdc++.h>
#define lol unsign long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n;
        cin >> n;
        if (n == 0)
            break;

        if (sqrtl(n) * 1ll * sqrtl(n) != n)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }

    return 0;
}