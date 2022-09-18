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

        lol a, b, c;
        cin >> a >> b >> c;
        b -= c;
        string c1 = "1";
        c--;
        while (c--)
        {
            c1.push_back('0');
        }

        string a1, b1;

        a1 = "1";
        b1 = c1;
        a--;

        while (a--)
        {

            a1 = a1 + "0";
        }
        while (b--)
        {
            b1 = "1" + b1;
        }

        cout << a1 << " " << b1 << endl;
    }

    return 0;
}