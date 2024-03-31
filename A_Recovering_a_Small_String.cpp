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
        lol a = 1, b = 1, c = 1;
        n -= 3;

        if (c + n <= 26)
        {
            c += n;
            n = 0;
        }
        else
        {
            n -= 26 - c;
            c = 26;
        }
        if (b + n <= 26)
        {
            b += n;
            n = 0;
        }
        else
        {
            n -= 26 - b;
            b = 26;
        }
        if (a + n <= 26)
        {
            a += n;
            n = 0;
        }
        else
        {
            n -= 26 - a;
            a = 26;
        }
        cout << char('a' + a - 1);
        cout << char('a' + b - 1);
        cout << char('a' + c - 1);
        cout << '\n';
    }

    return 0;
}
