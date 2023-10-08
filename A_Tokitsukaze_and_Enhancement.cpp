#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    n %= 4;
    if (n == 0)
    {
        cout << 1 << " A";
    }
    else if (n == 1)
    {
        cout << 0 << " A";
    }
    else if (n == 2)
    {
        cout << 1 << " B";
    }
    else
    {
        cout << 2 << " A";
    }
}