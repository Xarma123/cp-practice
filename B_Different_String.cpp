#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string a = s;
        sort(a.begin(), a.end());
        if (a != s)
        {
            cout << "YES\n";
            cout << a << '\n';
        }
        else
        {
            reverse(a.begin(), a.end());
            if (a != s)
            {
                cout << "YES\n";
                cout << a << '\n';
            }
            else
                cout << "NO\n";
        }
    }

    return 0;
}
