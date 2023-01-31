#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (5 - a[i] >= k)
            c++;
    }
    cout << c / 3;

    return 0;
}