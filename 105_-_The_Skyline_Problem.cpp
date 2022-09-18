#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<lol> c(10001, 0);
    lol l, h, r;
    while (cin >> l)
    {
        cin >> h >> r;
        for (lol i = l; i < r; i++)
        {
            c[i] = max(c[i], h);
        }
    }
    lol i = 0;
    while (i < 10001 && c[i] == 0)
        i++;
    if (i != 10001)
    {
        cout << i << " " << c[i];
        l = c[i];
        i++;
        while (i < 10001)
        {
            if (c[i] != l)
            {
                cout << " " << i << " " << c[i];
                l = c[i];
            }
            i++;
        }
    }
    cout << endl;

    return 0;
}