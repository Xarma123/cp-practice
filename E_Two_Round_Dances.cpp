#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol fact = 1;

    for (lol i = 1; i <= n; i++)
    {
        fact *= i;
    }

    cout << ((fact) / ((n / 2) * (n / 2) * 2));

    return 0;
}