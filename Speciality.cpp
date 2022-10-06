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
        if (a > b && a > c)
        {
            cout << "Setter" << endl;
        }
        else if (b > a && b > c)
        {
            cout << "Tester" << endl;
        }
        else
            cout << "Editorialist" << endl;
    }

    return 0;
}