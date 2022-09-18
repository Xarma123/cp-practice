#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    if (n % 2 == 0)
    {

        cout << pow((n / 2 + 1), 2);
    }
    else
        cout << (n / 2 + 2) * (n / 2 + 1) * 2;

    return 0;
}