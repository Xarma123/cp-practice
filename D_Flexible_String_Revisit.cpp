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
        lol n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if (a == b)
            cout << 0 << '\n';
        else if (n == 1)
        {
            cout << '1' << '\n';
        }
        
    }

    return 0;
}