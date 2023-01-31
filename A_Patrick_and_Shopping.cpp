#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c;
    cin >> a >> b >> c;
    cout << min((a + b + c), min(2ll * (a + c), min(2ll * (b + c), 2ll * (a + b))));

    return 0;
}