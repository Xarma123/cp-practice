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
    set<lol> x;
    lol p;
    cin >> p;
    while (p--)
    {
        lol a;
        cin >> a;
        x.insert(a);
    }
    cin >> p;
    while (p--)
    {
        lol a;
        cin >> a;
        x.insert(a);
    }
    if (x.size() == n)
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";

    return 0;
}