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
    unordered_set<lol> mp;
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp.count(a[i]))
        {
            c++;
            mp.erase(a[i]);
        }
        else
            mp.insert(a[i]);
    }
    cout << c / 2;

    return 0;
}