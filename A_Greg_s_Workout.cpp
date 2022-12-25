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
    lol a1 = 0, a2 = 0, a3 = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 3 == 0)
            a1 += a[i];
        else if (i % 3 == 1)
            a2 += a[i];
        else
        {
            a3 += a[i];
        }
    }
    if (a1 > a2 && a1 > a3)
        cout << "chest";
    else if (a2 > a1 && a2 > a3)
        cout << "biceps";
    else
        cout << "back";

    return 0;
}