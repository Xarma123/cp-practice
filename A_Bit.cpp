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
    lol x = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> s;
        bool f = false;
        for (auto c : s)
        {
            if (c == '+')
                f = true;
        }
        if (f)
            x++;
        else
            x--;
    }
    cout << x;

    return 0;
}