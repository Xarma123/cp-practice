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
    string a[10];
    a[0] = "O-|-OOOO";
    a[1] = "O-|O-OOO";
    a[2] = "O-|OO-OO";
    a[3] = "O-|OOO-O";
    a[4] = "O-|OOOO-";
    a[5] = "-O|-OOOO";
    a[6] = "-O|O-OOO";
    a[7] = "-O|OO-OO";
    a[8] = "-O|OOO-O";
    a[9] = "-O|OOOO-";
    while (1)
    {
        cout << a[(n % 10)] << '\n';
        n /= 10;
        if (n == 0)
            break;
    }

    return 0;
}