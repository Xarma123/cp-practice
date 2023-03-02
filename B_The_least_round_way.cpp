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
        lol x, y;
        cin >> x >> y;
        if (x % 2 == 0)
        {
            if (x > y)
                cout << "CHEF" << '\n';
            else
                cout << "CHEFINA" << '\n';
        }
        else
        {
            if (x > y + 1)
                cout << "CHEF" << '\n';
            else if (x == y + 1)
                cout << "CHEFINA" << '\n';
            else if (x == y)
            {
                cout << "CHEF" << '\n';
            }
            else if (x == y - 1)
            {
                cout << "CHEF" << '\n';
            }
            else
                cout << "CHEFINA" << '\n';
        }
    }

    return 0;
}