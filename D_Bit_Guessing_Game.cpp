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
        lol c;
        cin >> c;
        lol n = 0;
        lol ct = 0;
        lol bit = 0;
        while (ct < c && bit < 31)
        {
            cout << "- " << (1ll << bit) << endl;
            lol cn;
            cin >> cn;
            if (cn == c - 1)
            {
                n |= (1ll << bit);
                bit++;
                c = cn;
            }
            else
            {
                n |= (1ll << (bit + 1 + cn - c));
                bit += 2 + cn - c;
                ct += cn - c + 1;
                c = cn;
            }
        }
        cout << "! " << n << endl;
    }

    return 0;
}