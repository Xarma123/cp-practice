#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol sum;
        cin >> sum;
        lol n = sqrt(sum);
        if (n * n == sum)
            cout << n << endl;
        else
            cout << n + 1 << endl;
    }

    return 0;
}