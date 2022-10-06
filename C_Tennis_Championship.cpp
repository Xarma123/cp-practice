#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    if (n == 2)
    {
        cout << 1;
    }
    else if (n == 3)
        cout << 2;
    else if (n == 4)
        cout << 2;
    else
    {
        lol a = 2;
        lol b = 3;
        lol c = a + b;
        lol q = 3;
        while (c < n)
        {
            a = b;
            b = c;
            c = a + b;
            q++;
        }
        cout << q;
    }

    return 0;
}