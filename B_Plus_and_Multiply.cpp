#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, n;
        cin >> n >> a >> b;
        bool f = true;
        lol p = 1;
        while (1)
        {
            if (n >= p)
            {
                lol check = n - p;
                if (check % b == 0)
                {
                    f = false;
                    cout << "Yes" << endl;
                    break;
                }
            }
            else
            {
                break;
            }
            p = p * a; 
            if(a==1)
            {
                break;
            }
        }
        if (f)
            cout << "No" << endl;
    }

    return 0;
}