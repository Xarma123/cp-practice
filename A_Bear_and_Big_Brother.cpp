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
    lol c = 0;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        c++;
    }
    cout << c;

    return 0;
}