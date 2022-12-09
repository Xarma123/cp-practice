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
    map<lol, vector<lol>> mp;
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            c++;
    }
    if (c <= 2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}