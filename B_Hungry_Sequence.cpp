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
    lol a = 1e6;
    for (lol i = 0; i < n; i++)
    {
        cout << a << " ";
        a++;
    }

    return 0;
}