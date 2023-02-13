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
    lol c = 0;
    for (auto e : s)
    {
        if (e == 'x')
            c++;
    }
    cout << abs(c - n / 2) << '\n';
    if (c < n / 2)
    {
        for (lol i = 0; i < n && c < n / 2; i++)
        {
            if (s[i] == 'X')
                s[i] = 'x', c++;
        }
    }
    else if (c > n / 2)
    {
        for (lol i = 0; i < n && c > n / 2; i++)
        {
            if (s[i] == 'x')
                s[i] = 'X', c--;
        }
    }
    cout << s;

    return 0;
}