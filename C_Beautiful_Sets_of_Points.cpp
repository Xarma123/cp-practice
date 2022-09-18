#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    cout << min(n, m) + 1 << endl;
    lol x = n, y = 0;
    while (y <= m && x >= 0)
    {
        cout << x << " " << y << endl;
        x--;
        y++;
    } 
    

    return 0;
}