#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a = 2 * n + 3;
    lol b = sqrtl(8 * n + 8 * k + 9);
    if ((a + b) % 2 == 0&&(a+b)/2<=n)
    {
        cout << (a + b) / 2;
    }
    else
        cout << (a - b) / 2;

    return 0;
}