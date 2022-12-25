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
    lol a = 0, i = 0;
    for (auto c : s)
    {
        if (c == 'A')
            a++;
        else if (c == 'I')
            i++;
    }
    if (i == 1)
        cout << 1;
    else if (i > 1)
        cout << 0;
    else
        cout << a;

    return 0;
}