#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        lol x;
        cin >> x;
        bool flag = false;
        while (x >=0)
        {

            if (x % 11 == 0)
            {
                flag = true;
                break;
            }
            else
            {
                x -= 111;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
