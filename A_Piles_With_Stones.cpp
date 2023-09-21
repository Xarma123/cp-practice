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
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        lol v;
        cin >> v;
        s += v;
    }
    for (lol i = 0; i < n; i++)
    {
        lol v;
        cin >> v;
        s -= v;
    }
    if (s >= 0)
        cout << "Yes";
    else
        cout << "No";
}