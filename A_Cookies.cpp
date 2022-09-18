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
    lol a[n];
    lol ans = 0;
    lol sum = 0;
    lol e = 0, o = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 0)
            e++;
        else
            o++;
    }
    if (sum % 2 == 0)
    {
        cout << e;
    }
    else
        cout << o;

    return 0;
}