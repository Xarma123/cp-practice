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
        lol n;
        cin >> n;
        // find  largest power of two less than or equal to n
        cout << (1ll << (long long)floorl(log2l(n))) << '\n';
    }

    return 0;
}
