#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol a, b, r;
    cin >> a >> b >> r;
    if (2 * r > min(a, b))
    {
        cout << "Second";
    }
    else
        cout << "First";

    return 0;
}