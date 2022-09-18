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
        n -= 6;
        lol h2 = 3;
        h2 += n / 3;
        if (n % 3 != 0)
            h2++;

        lol h3 = 1;
        h3 += n / 3;
        lol h1 = 2;
        h1 += n / 3;
        if (n % 3 == 2)
            h1++;
        cout << h1 << " " << h2 << " " << h3 << endl;
    }

    return 0;
}