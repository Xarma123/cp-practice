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

    lol f1[3];
    memset(f1, 0, sizeof(f1));
    while (a % 2 == 0)
    {
        f1[0]++;
        a /= 2;
    }
    while (a % 3 == 0)
    {
        f1[1]++;
        a /= 3;
    }
    while (a % 5 == 0)
    {
        f1[2]++;
        a /= 5;
    }
    lol f2[3];
    memset(f2, 0, sizeof(f2));
    while (b % 2 == 0)
    {
        f2[0]++;
        b /= 2;
    }
    while (b % 3 == 0)
    {
        f2[1]++;
        b /= 3;
    }
    while (b % 5 == 0)
    {
        f2[2]++;
        b /= 5;
    }

    if (a != b)
    {
        cout << -1;
    }
    else
    {
        cout << abs(f1[0] - f2[0]) + abs(f1[1] - f2[1]) + abs(f1[2] - f2[2]);
    }

    return 0;
}