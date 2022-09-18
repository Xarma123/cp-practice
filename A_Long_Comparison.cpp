#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol p1, p2;
        string x1, x2;
        cin >> x1 >> p1 >> x2 >> p2;

        if (x1.size() > x2.size())
        {
            while (x2.size() != x1.size() && p2)
            {
                x2 = x2 + "0";
                p2--;
            }
        }
        else if (x1.size() < x2.size())
        {
            while (x1.size() != x2.size() && p1)
            {
                x1 = x1 + "0";
                p1--;
            }
        }
        if (x1.size() + p1 > x2.size() + p2)
            cout << '>' << endl;
        else if (x1.size() + p1 < x2.size() + p2)
            cout << '<' << endl;

        else if (x1 == x2)
            cout << '=' << endl;
        else if (x1 > x2)
            cout << '>' << endl;
        else
            cout << '<' << endl;
    }

    return 0;
}