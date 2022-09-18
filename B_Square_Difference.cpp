#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        if (a == b + 1)
        {
            lol v = a + b;
            bool ans = true;
            for (lol i = 2; i * i <= v; i++)
            {
                if (v % i == 0)
                {
                    ans = false;
                    break;
                }
            }
            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}