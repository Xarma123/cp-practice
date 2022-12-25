#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol l, r;
        cin >> l >> r;
        if (l == 0 && r == 0)
            break;
        lol z1 = 0;
        lol d = 5;
        // while (l / d > 0)
        {
            z1 += l / d;    
            // d = d * 5ll;
        }
        lol z2 = 0;
        // d = 5;
        // while (r / d > 0)
        {
            z2 += r / d;
            // d = d * 5ll;
        }
        cout << z2 - z1 + 1 << endl;
    }

    return 0;
}