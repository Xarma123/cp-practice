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
        string a;
        cin >> a;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] == '7')
            {
                cout << 79 << '\n';
                break;
            }
            if (a[i] == '9')
            {
                cout << 97 << '\n';
                break;
            }
        }
    }
}