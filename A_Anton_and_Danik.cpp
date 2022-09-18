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
    string s;
    cin >> s;
    lol a = 0;
    for (auto e : s)
    {
        if (e == 'A')
            a++;
    }
    if (a > n - a)
        cout << "Anton";
    else if (a == n - a)
        cout << "Friendship";
    else
        cout << "Danik";

    return 0;
}