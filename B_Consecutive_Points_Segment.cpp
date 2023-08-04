#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol x[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        bool ans = false;
        bool c = true;
        for (lol i = 1; i < n; i++)
        {
            c &= ((long long)abs(x[0] + i - x[i]) <= 1);
        }
        ans |= c;
        c = true;
        for (lol i = 1; i < n; i++)
        {
            c &= ((long long)abs(x[0] + 1 + i - x[i]) <= 1);
        }
        ans |= c;
        c = true;
        for (lol i = 1; i < n; i++)
        {
            c &= ((long long)abs(x[0] - 1 + i - x[i]) <= 1);
        }
        ans |= c;
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}