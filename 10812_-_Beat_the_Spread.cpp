#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    while (n--)
    {
        lol s, d;
        cin >> s >> d;
        if ((s + d) % 2 != 0 || (s - d) % 2 != 0 || (s - d) < 0)
            cout << "impossible" << endl;
        else
            cout << (s + d) / 2 << " " << (s - d) / 2 << endl;
    }

    return 0;
}