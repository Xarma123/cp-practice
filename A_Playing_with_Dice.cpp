#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b;
    cin >> a >> b;
    lol c[3];
    c[0] = c[1] = c[2] = 0;
    for (lol i = 1; i <= 6; i++)
    {
        if (abs(a - i) < abs(b - i))
            c[0]++;
        else if (abs(a - i) == abs(b - i))
            c[1]++;
        else
            c[2]++;
    }
    for (lol i = 0; i < 3; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}