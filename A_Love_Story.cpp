#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string a = "codeforces";
        lol c = 0;
        for (lol i = 0; i < 10; i++)
        {
            if (a[i] != s[i])
                c++;
        }
        cout << c << '\n';
    }

    return 0;
}