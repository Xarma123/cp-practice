#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol x, y, z;
    cin >> x >> y >> z;
    cout << (x + y) / z << " ";
    if ((x % z) + (y % z) >= z)
        cout << min(z - (x % z), z - (y % z));
    else
        cout << 0;
}